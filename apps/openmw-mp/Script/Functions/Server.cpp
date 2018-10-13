#include "Server.hpp"

#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Log.hpp>
#include <components/openmw-mp/Version.hpp>

#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>
#include <apps/openmw-mp/MasterClient.hpp>


void ServerFunctions::StopServer(int code) noexcept
{
    mwmp::Networking::getPtr()->stopServer(code);
}

void ServerFunctions::Kick(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Kicking player %s (%i)", player->npc.mName.c_str(), player->getId());
    mwmp::Networking::getPtr()->kickPlayer(player->guid);
}

void ServerFunctions::BanAddress(const char *ipAddress) noexcept
{
    mwmp::Networking::getPtr()->banAddress(ipAddress);
}

void ServerFunctions::UnbanAddress(const char *ipAddress) noexcept
{
    mwmp::Networking::getPtr()->unbanAddress(ipAddress);
}

const char *ServerFunctions::GetServerVersion() noexcept
{
    return TES3MP_VERSION;
}

const char *ServerFunctions::GetProtocolVersion() noexcept
{
    static std::string version = std::to_string(TES3MP_PROTO_VERSION);
    return version.c_str();
}

int ServerFunctions::GetAvgPing(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, -1);
    return mwmp::Networking::get().getAvgPing(player->guid);
}

const char *ServerFunctions::GetIP(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");
    RakNet::SystemAddress addr = mwmp::Networking::getPtr()->getSystemAddress(player->guid);
    return addr.ToString(false);
}

unsigned short ServerFunctions::GetPort() noexcept
{
    return mwmp::Networking::get().getPort();
}

unsigned int ServerFunctions::GetMaxPlayers() noexcept
{
    return mwmp::Networking::get().maxConnections();
}

bool ServerFunctions::HasPassword() noexcept
{
    return mwmp::Networking::get().isPassworded();
}

void ServerFunctions::SetGameMode(const char *gameMode) noexcept
{
    if (mwmp::Networking::getPtr()->getMasterClient())
        mwmp::Networking::getPtr()->getMasterClient()->SetModname(gameMode);
}

void ServerFunctions::SetHostname(const char *name) noexcept
{
    if (mwmp::Networking::getPtr()->getMasterClient())
        mwmp::Networking::getPtr()->getMasterClient()->SetHostname(name);
}

void ServerFunctions::SetServerPassword(const char *password) noexcept
{
    mwmp::Networking::getPtr()->setServerPassword(password);
}

void ServerFunctions::SetRuleString(const char *key, const char *value) noexcept
{
    auto mc = mwmp::Networking::getPtr()->getMasterClient();
    if (mc)
        mc->SetRuleString(key, value);
}

void ServerFunctions::SetRuleValue(const char *key, double value) noexcept
{
    auto mc = mwmp::Networking::getPtr()->getMasterClient();
    if (mc)
        mc->SetRuleValue(key, value);
}
