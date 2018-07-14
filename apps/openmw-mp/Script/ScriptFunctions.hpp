#ifndef SCRIPTFUNCTIONS_HPP
#define SCRIPTFUNCTIONS_HPP

#include <Script/Functions/Actors.hpp>
#include <Script/Functions/Books.hpp>
#include <Script/Functions/Cells.hpp>
#include <Script/Functions/CharClass.hpp>
#include <Script/Functions/Chat.hpp>
#include <Script/Functions/Dialogue.hpp>
#include <Script/Functions/Factions.hpp>
#include <Script/Functions/GUI.hpp>
#include <Script/Functions/Items.hpp>
#include <Script/Functions/Mechanics.hpp>
#include <Script/Functions/Miscellaneous.hpp>
#include <Script/Functions/Objects.hpp>
#include <Script/Functions/Positions.hpp>
#include <Script/Functions/Quests.hpp>
#include <Script/Functions/Shapeshift.hpp>
#include <Script/Functions/Server.hpp>
#include <Script/Functions/Settings.hpp>
#include <Script/Functions/Spells.hpp>
#include <Script/Functions/Stats.hpp>
#include <Script/Functions/Worldstate.hpp>
#include <RakNetTypes.h>
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

            ACTORAPI,
            BOOKAPI,
            CELLAPI,
            CHARCLASSAPI,
            CHATAPI,
            DIALOGUEAPI,
            FACTIONAPI,
            GUIAPI,
            ITEMAPI,
            MECHANICSAPI,
            MISCELLANEOUSAPI,
            POSITIONAPI,
            QUESTAPI,
            SHAPESHIFTAPI,
            SERVERAPI,
            SETTINGSAPI,
            SPELLAPI,
            STATAPI,
            OBJECTAPI,
            WORLDSTATEAPI
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
            {"OnPlayerInput",            Function<void, unsigned short>()},
            {"OnPlayerRest",             Function<void, unsigned short>()},
            {"OnRecordDynamic",          Function<void, unsigned short>()},
            {"OnCellLoad",               Function<void, unsigned short, const char*>()},
            {"OnCellUnload",             Function<void, unsigned short, const char*>()},
            {"OnCellDeletion",           Function<void, const char*>()},
            {"OnContainer",              Function<void, unsigned short, const char*>()},
            {"OnDoorState",              Function<void, unsigned short, const char*>()},
            {"OnObjectActivate",         Function<void, unsigned short, const char*>()},
            {"OnObjectPlace",            Function<void, unsigned short, const char*>()},
            {"OnObjectState",            Function<void, unsigned short, const char*>()},
            {"OnObjectSpawn",            Function<void, unsigned short, const char*>()},
            {"OnObjectDelete",           Function<void, unsigned short, const char*>()},
            {"OnObjectLock",             Function<void, unsigned short, const char*>()},
            {"OnObjectScale",            Function<void, unsigned short, const char*>()},
            {"OnObjectTrap",             Function<void, unsigned short, const char*>()},
            {"OnVideoPlay",              Function<void, unsigned short, const char*>()},
            {"OnActorList",              Function<void, unsigned short, const char*>()},
            {"OnActorEquipment",         Function<void, unsigned short, const char*>()},
            {"OnActorAI",                Function<void, unsigned short, const char*>()},
            {"OnActorDeath",             Function<void, unsigned short, const char*>()},
            {"OnActorCellChange",        Function<void, unsigned short, const char*>()},
            {"OnActorTest",              Function<void, unsigned short, const char*>()},
            {"OnPlayerSendMessage",      Function<bool, unsigned short, const char*>()},
            {"OnPlayerEndCharGen",       Function<void, unsigned short>()},
            {"OnGUIAction",              Function<void, unsigned short, int, const char*>()},
            {"OnWorldMap",               Function<void, unsigned short>()},
            {"OnMpNumIncrement",         Function<void, int>()},
            {"OnRequestPluginList",      Function<const char *, unsigned int, unsigned int>()}
    };
};

#endif //SCRIPTFUNCTIONS_HPP
