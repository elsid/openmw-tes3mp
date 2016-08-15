#include <RakPeerInterface.h>
#include <BitStream.h>
#include "Player.hpp"
#include "Networking.hpp"
#include "MasterClient.hpp"
#include "Log.hpp"
#include <RakPeer.h>
#include <MessageIdentifiers.h>
#include <components/openmw-mp/NetworkMessages.hpp>
#include <apps/openmw-mp/Script/Script.hpp>
#include <iostream>
#include <components/files/configurationmanager.hpp>
#include <components/settings/settings.hpp>
#include <thread>

using namespace std;
using namespace mwmp;

void printVersion(string version, int protocol)
{
    cout << "TES3:MP dedicated server " << version;
    cout << " (";
#ifdef _WIN32
    cout << "Windows";
#elif __linux
    cout << "Linux";
#elif __APPLE__
    cout << "OS X";
#else
    cout << "Unknown OS";
#endif
    cout << " ";
#ifdef __x86_64__
    cout << "64-bit";
#elif defined __i386__ || defined _M_I86
    cout << "32-bit";
#else
    cout << "Unknown architecture";
#endif
    cout << ")" << endl;
    cout << "Protocol version: " << protocol << endl;

    cout << "------------------------------------------------------------" << endl;
}

std::string loadSettings (Settings::Manager & settings)
{
    Files::ConfigurationManager mCfgMgr;
    // Create the settings manager and load default settings file
    const std::string localdefault = (mCfgMgr.getLocalPath() / "tes3mp-server-default.cfg").string();
    const std::string globaldefault = (mCfgMgr.getGlobalPath() / "tes3mp-server-default.cfg").string();

    // prefer local
    if (boost::filesystem::exists(localdefault))
        settings.loadDefault(localdefault);
    else if (boost::filesystem::exists(globaldefault))
        settings.loadDefault(globaldefault);
    else
        throw std::runtime_error ("No default settings file found! Make sure the file \"tes3mp-server-default.cfg\" was properly installed.");

    // load user settings if they exist
    const std::string settingspath = (mCfgMgr.getUserConfigPath() / "tes3mp-server.cfg").string();
    if (boost::filesystem::exists(settingspath))
        settings.loadUser(settingspath);

    return settingspath;
}

void queryThread(MasterClient *mclient)
{
    mclient->Update();
}

int main(int argc, char *argv[])
{
    Settings::Manager mgr;

    loadSettings(mgr);

    int logLevel = mgr.getInt("loglevel", "General");
    if(logLevel < Log::LOG_INFO || logLevel > Log::LOG_FATAL)
        logLevel = Log::LOG_INFO;
    LOG_INIT(logLevel);

    int players = mgr.getInt("players", "General");
    string addr = mgr.getString("address", "General");
    int port = mgr.getInt("port", "General");

    string plugin_home = mgr.getString("home", "Plugins");
    string moddir = Utils::convertPath(plugin_home + "/files");

    vector<string> plugins (Utils::split(mgr.getString("plugins", "Plugins"), ','));

    printVersion("0.0.1b", 1);


    setenv("AMXFILE", moddir.c_str(), 1);
    setenv("MOD_DIR", moddir.c_str(), 1); // hack for lua

    setenv("LUA_PATH", Utils::convertPath(plugin_home + "/scripts/?.lua" + ";" + plugin_home + "/scripts/?.t").c_str(), 1);

    for(auto plugin : plugins)
        Script::LoadScript(plugin.c_str(), plugin_home.c_str());

    RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();

    const char passw[8] = "1234567";
    peer->SetIncomingPassword(passw, sizeof(passw));

    if(RakNet::NonNumericHostString(addr.c_str()))
    {
        LOG_MESSAGE_SIMPLE(Log::LOG_ERROR, "%s", "You cannot use non numeric addresses for server.");
        return 1;
    }

    RakNet::SocketDescriptor sd((unsigned short)port, addr.c_str());
    if (peer->Startup((unsigned)players, &sd, 1) != RakNet::RAKNET_STARTED)
        return 1;

    peer->SetMaximumIncomingConnections((unsigned short)(players));

    Networking networking(peer);

    bool masterEnabled = mgr.getBool("enabled", "MasterServer");
    thread thrQuery;
    MasterClient *mclient;
    if(masterEnabled)
    {
        LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "%s", "Sharing server query info to master enabled.");
        string masterAddr = mgr.getString("address", "MasterServer");
        int masterPort = mgr.getInt("port", "MasterServer");
        mclient = new MasterClient(masterAddr, (unsigned short) masterPort, addr, (unsigned short) port);
        mclient->SetMaxPlayers((unsigned)players);
        string motd = mgr.getString("motd", "General");
        mclient->SetMOTD(motd);
        thrQuery = thread(queryThread, mclient);
    }
    

    int code = networking.MainLoop();

    RakNet::RakPeerInterface::DestroyInstance(peer);

    if(thrQuery.joinable())
    {
        mclient->Stop();
        thrQuery.join();
    }

    if (code == 0)
        LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "%s", "Quitting peacefully.");

    LOG_QUIT();
    return code;
}