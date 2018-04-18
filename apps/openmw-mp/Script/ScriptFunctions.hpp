//
// Created by koncord on 24.01.16.
//

#ifndef SCRIPTFUNCTIONS_HPP
#define SCRIPTFUNCTIONS_HPP

#include <Script/Functions/Actors.hpp>
#include <Script/Functions/Books.hpp>
#include <Script/Functions/Cells.hpp>
#include <Script/Functions/CharClass.hpp>
#include <Script/Functions/Dialogue.hpp>
#include <Script/Functions/Factions.hpp>
#include <Script/Functions/GUI.hpp>
#include <Script/Functions/Items.hpp>
#include <Script/Functions/Mechanics.hpp>
#include <Script/Functions/Miscellaneous.hpp>
#include <Script/Functions/Positions.hpp>
#include <Script/Functions/Quests.hpp>
#include <Script/Functions/Shapeshift.hpp>
#include <Script/Functions/Settings.hpp>
#include <Script/Functions/Spells.hpp>
#include <Script/Functions/Stats.hpp>
#include <Script/Functions/World.hpp>
#include <RakNetTypes.h>
//#include <amx/amx.h>
#include <tuple>
#include <apps/openmw-mp/Player.hpp>
#include "ScriptFunction.hpp"
#include "Types.hpp"

#include <components/openmw-mp/Log.hpp>

#define GET_PLAYER(pid, pl, retvalue) \
     pl = Players::getPlayer(pid); \
     if (player == 0) {\
        LOG_MESSAGE_SIMPLE(Log::LOG_ERROR, "%s: Player with pid \'%d\' not found\n", __PRETTY_FUNCTION__, pid);\
        /*ScriptFunctions::StopServer(1);*/ \
        return retvalue;\
}


class ScriptFunctions
{
public:

    static void GetArguments(std::vector<boost::any> &params, va_list args, const std::string &def);
    static void MakePublic(ScriptFunc _public, const char *name, char ret_type, const char *def) noexcept;
    static boost::any CallPublic(const char *name, va_list args) noexcept;

    /**
    * \brief Shut down the server.
    *
    * \param code The shutdown code.
    * \return void
    */
    static void StopServer(int code) noexcept;

    /**
    * \brief Send a message to a certain player.
    *
    * \param pid The player ID.
    * \param message The contents of the message.
    * \param broadcast Whether the message should also be sent to other players.
    * \return void
    */
    static void SendMessage(unsigned short pid, const char *message, bool broadcast) noexcept;

    /**
    * \brief Remove all messages from chat for a certain player.
    *
    * \param pid The player ID.
    * \return void
    */
    static void CleanChatByPid(unsigned short pid);

    /**
    * \brief Remove all messages from chat for everyone on the server.
    *
    * \return void
    */
    static void CleanChat();

     /**
     * \brief Create a timer that will run a script function after a certain interval.
     *
     * \param callback The Lua script function.
     * \param msec The interval in miliseconds.
     * \return The ID of the timer thus created.
     */
    static int CreateTimer(ScriptFunc callback, int msec) noexcept;

    /**
    * \brief Create a timer that will run a script function after a certain interval and pass
    *        certain arguments to it.
    *
    * Example usage:
    * - tes3mp.CreateTimerEx("OnTimerTest1", 250, "i", 90)
    * - tes3mp.CreateTimerEx("OnTimerTest2", 500, "sif", "Test string", 60, 77.321)
    *
    * \param callback The Lua script function.
    * \param msec The interval in miliseconds.
    * \param types The argument types.
    * \param args The arguments.
    * \return The ID of the timer thus created.
    */
    static int CreateTimerEx(ScriptFunc callback, int msec, const char *types, va_list args) noexcept;

    /**
    * \brief Start the timer with a certain ID.
    *
    * \param timerId The timer ID.
    * \return void
    */
    static void StartTimer(int timerId) noexcept;

    /**
    * \brief Stop the timer with a certain ID.
    *
    * \param timerId The timer ID.
    * \return void
    */
    static void StopTimer(int timerId) noexcept;

    /**
    * \brief Restart the timer with a certain ID for a certain interval.
    *
    * \param timerId The timer ID.
    * \param msec The interval in miliseconds.
    * \return void
    */
    static void RestartTimer(int timerId, int msec) noexcept;

    /**
    * \brief Free the timer with a certain ID.
    *
    * \param timerId The timer ID.
    * \return void
    */
    static void FreeTimer(int timerId) noexcept;

    /**
    * \brief Check whether a timer is elapsed.
    *
    * \param timerId The timer ID.
    * \return Whether the timer is elapsed.
    */
    static bool IsTimerElapsed(int timerId) noexcept;

    /**
    * \brief Kick a certain player from the server.
    *
    * \param pid The player ID.
    * \return void
    */
    static void Kick(unsigned short pid) noexcept;

    /**
    * \brief Ban a certain IP address from the server.
    *
    * \param ipAddress The IP address.
    * \return void
    */
    static void BanAddress(const char *ipAddress) noexcept;

    /**
    * \brief Unban a certain IP address from the server.
    *
    * \param ipAddress The IP address.
    * \return void
    */
    static void UnbanAddress(const char *ipAddress) noexcept;

    /**
    * \brief Get the TES3MP version of the server.
    *
    * \return The server version.
    */
    static const char *GetServerVersion() noexcept;

    /**
    * \brief Get the protocol version of the server.
    *
    * \return The protocol version.
    */
    static const char *GetProtocolVersion() noexcept;

    /**
    * \brief Get the average ping of a certain player.
    *
    * \param pid The player ID.
    * \return The average ping.
    */
    static int GetAvgPing(unsigned short pid) noexcept;

    /**
    * \brief Get the IP address of a certain player.
    *
    * \param pid The player ID.
    * \return The IP address.
    */
    static const char* GetIP(unsigned short pid) noexcept;

    /**
    * \brief Set the game mode of the server, as displayed in the server browser.
    *
    * \param name The new game mode.
    * \return void
    */
    static void SetModname(const char* name) noexcept;

    /**
    * \brief Set the name of the server, as displayed in the server browser.
    *
    * \param name The new name.
    * \return void
    */
    static void SetHostname(const char* name) noexcept;

    /**
    * \brief Set the password required to join the server.
    *
    * \param password The password.
    * \return void
    */
    static void SetServerPassword(const char *passw) noexcept;

    /**
    * \brief Set a rule string for the server details displayed in the server browser.
    *
    * \param key The name of the rule.
    * \param value The string value of the rule.
    * \return void
    */
    static void SetRuleString(const char *key, const char *value) noexcept;

    /**
    * \brief Set a rule value for the server details displayed in the server browser.
    *
    * \param key The name of the rule.
    * \param value The numerical value of the rule.
    * \return void
    */
    static void SetRuleValue(const char *key, double value) noexcept;

    static constexpr ScriptFunctionData functions[]{
            {"CreateTimer",         ScriptFunctions::CreateTimer},
            {"CreateTimerEx",       reinterpret_cast<Function<void>>(ScriptFunctions::CreateTimerEx)},
            {"MakePublic",          ScriptFunctions::MakePublic},
            {"CallPublic",          reinterpret_cast<Function<void>>(ScriptFunctions::CallPublic)},

            {"StartTimer",          ScriptFunctions::StartTimer},
            {"StopTimer",           ScriptFunctions::StopTimer},
            {"RestartTimer",        ScriptFunctions::RestartTimer},
            {"FreeTimer",           ScriptFunctions::FreeTimer},
            {"IsTimerElapsed",      ScriptFunctions::IsTimerElapsed},

            {"StopServer",          ScriptFunctions::StopServer},

            {"SendMessage",         ScriptFunctions::SendMessage},

            {"Kick",                ScriptFunctions::Kick},
            {"BanAddress",          ScriptFunctions::BanAddress},
            {"UnbanAddress",        ScriptFunctions::UnbanAddress},

            {"GetServerVersion",    ScriptFunctions::GetServerVersion},
            {"GetProtocolVersion",  ScriptFunctions::GetProtocolVersion},
            {"GetAvgPing",          ScriptFunctions::GetAvgPing},
            {"SetModname",          ScriptFunctions::SetModname},
            {"SetHostname",         ScriptFunctions::SetHostname},
            {"SetServerPassword",   ScriptFunctions::SetServerPassword},
            {"SetRuleString",       ScriptFunctions::SetRuleString},
            {"SetRuleValue",        ScriptFunctions::SetRuleValue},
            {"CleanChatByPid",      ScriptFunctions::CleanChatByPid},
            {"CleanChat",           ScriptFunctions::CleanChat},
            {"GetIP",               ScriptFunctions::GetIP},

            ACTORAPI,
            BOOKAPI,
            CELLAPI,
            CHARCLASSAPI,
            DIALOGUEAPI,
            FACTIONAPI,
            GUIAPI,
            ITEMAPI,
            MECHANICSAPI,
            MISCELLANEOUSAPI,
            POSITIONAPI,
            QUESTAPI,
            SHAPESHIFTAPI,
            SETTINGSAPI,
            SPELLAPI,
            STATAPI,
            WORLDAPI
    };

    static constexpr ScriptCallbackData callbacks[]{
            {"Main",                     Function<int, int, int>()},
            {"OnServerInit",             Function<void>()},
            {"OnServerPostInit",         Function<void>()},
            {"OnServerExit",             Function<void, bool>()},
            {"OnPlayerConnect",          Function<bool, unsigned short>()},
            {"OnPlayerDisconnect",       Function<void, unsigned short>()},
            {"OnPlayerDeath",            Function<void, unsigned short>()},
            {"OnPlayerResurrect",        Function<void, unsigned short>()},
            {"OnPlayerCellChange",       Function<void, unsigned short>()},
            {"OnPlayerKillCount",        Function<void, unsigned short>()},
            {"OnPlayerAttribute",        Function<void, unsigned short>()},
            {"OnPlayerSkill",            Function<void, unsigned short>()},
            {"OnPlayerLevel",            Function<void, unsigned short>()},
            {"OnPlayerBounty",           Function<void, unsigned short>()},
            {"OnPlayerReputation",       Function<void, unsigned short>()},
            {"OnPlayerEquipment",        Function<void, unsigned short>()},
            {"OnPlayerInventory",        Function<void, unsigned short>()},
            {"OnPlayerJournal",          Function<void, unsigned short>()},
            {"OnPlayerFaction",          Function<void, unsigned short>()},
            {"OnPlayerShapeshift",       Function<void, unsigned short>()},
            {"OnPlayerSpellbook",        Function<void, unsigned short>()},
            {"OnPlayerQuickKeys",        Function<void, unsigned short>()},
            {"OnPlayerTopic",            Function<void, unsigned short>()},
            {"OnPlayerDisposition",      Function<void, unsigned short>()},
            {"OnPlayerBook",             Function<void, unsigned short>()},
            {"OnPlayerMiscellaneous",    Function<void, unsigned short>()},
            {"OnPlayerMap",              Function<void, unsigned short>()},
            {"OnPlayerInteraction",      Function<void, unsigned short>()},
            {"OnPlayerRest",             Function<void, unsigned short>()},
            {"OnRecordDynamic",          Function<void, unsigned short>()},
            {"OnCellLoad",               Function<void, unsigned short, const char*>()},
            {"OnCellUnload",             Function<void, unsigned short, const char*>()},
            {"OnCellDeletion",           Function<void, const char*>()},
            {"OnContainer",              Function<void, unsigned short, const char*>()},
            {"OnDoorState",              Function<void, unsigned short, const char*>()},
            {"OnObjectPlace",            Function<void, unsigned short, const char*>()},
            {"OnObjectState",            Function<void, unsigned short, const char*>()},
            {"OnObjectSpawn",            Function<void, unsigned short, const char*>()},
            {"OnObjectDelete",           Function<void, unsigned short, const char*>()},
            {"OnObjectLock",             Function<void, unsigned short, const char*>()},
            {"OnObjectScale",            Function<void, unsigned short, const char*>()},
            {"OnObjectTrap",             Function<void, unsigned short, const char*>()},
            {"OnActorList",              Function<void, unsigned short, const char*>()},
            {"OnActorEquipment",         Function<void, unsigned short, const char*>()},
            {"OnActorCellChange",        Function<void, unsigned short, const char*>()},
            {"OnActorTest",              Function<void, unsigned short, const char*>()},
            {"OnPlayerSendMessage",      Function<bool, unsigned short, const char*>()},
            {"OnPlayerEndCharGen",       Function<void, unsigned short>()},
            {"OnGUIAction",              Function<void, unsigned short, int, const char*>()},
            {"OnMpNumIncrement",         Function<void, int>()},
            {"OnRequestPluginList",      Function<const char *, unsigned int, unsigned int>()}
    };
};

#endif //SCRIPTFUNCTIONS_HPP
