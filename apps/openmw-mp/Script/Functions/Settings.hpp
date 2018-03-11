#ifndef OPENMW_SETTINGSAPI_HPP
#define OPENMW_SETTINGSAPI_HPP

#include "../Types.hpp"

#define SETTINGSAPI \
    {"SetDifficulty",               SettingFunctions::SetDifficulty},\
    {"SetEnforcedLogLevel",         SettingFunctions::SetEnforcedLogLevel},\
    {"SetPhysicsFramerate",         SettingFunctions::SetPhysicsFramerate},\
    \
    {"SetConsoleAllowed",           SettingFunctions::SetConsoleAllowed},\
    {"SetBedRestAllowed",           SettingFunctions::SetBedRestAllowed},\
    {"SetWildernessRestAllowed",    SettingFunctions::SetWildernessRestAllowed},\
    {"SetWaitAllowed",              SettingFunctions::SetWaitAllowed},\
    \
    {"SendSettings",                SettingFunctions::SendSettings}

class SettingFunctions
{
public:

    /**
    * \brief Set the difficulty for a player.
    *
    * This changes the difficulty for that player in the server memory, but does not by itself
    * send a packet.
    *
    * \param pid The player ID.
    * \param bool The difficulty.
    * \return void
    */
    static void SetDifficulty(unsigned short pid, int difficulty);

    /**
    * \brief Set the client log level enforced for a player.
    *
    * This changes the enforced log level for that player in the server memory, but does not by itself
    * send a packet.
    *
    * Enforcing a certain log level is necessary to prevent players from learning information from
    * their console window that they are otherwise unable to obtain, such as the locations of
    * other players.
    *
    * If you do not wish to enforce a log level, simply set enforcedLogLevel to -1
    *
    * \param pid The player ID.
    * \param bool The enforced log level.
    * \return void
    */
    static void SetEnforcedLogLevel(unsigned short pid, int enforcedLogLevel);

    /**
    * \brief Set the physics framerate for a player.
    *
    * This changes the physics framerate for that player in the server memory, but does not by itself
    * send a packet.
    *
    * \param pid The player ID.
    * \param bool The physics framerate.
    * \return void
    */
    static void SetPhysicsFramerate(unsigned short pid, double physicsFramerate);

    /**
    * \brief Set whether the console is allowed for a player.
    *
    * This changes the console permission for that player in the server memory, but does not
    * by itself send a packet.
    *
    * \param pid The player ID.
    * \param bool The console permission state.
    * \return void
    */
    static void SetConsoleAllowed(unsigned short pid, bool state);

    /**
    * \brief Set whether resting in beds is allowed for a player.
    *
    * This changes the resting permission for that player in the server memory, but does not
    * by itself send a packet.
    *
    * \param pid The player ID.
    * \param bool The resting permission state.
    * \return void
    */
    static void SetBedRestAllowed(unsigned short pid, bool state);

    /**
    * \brief Set whether resting in the wilderness is allowed for a player.
    *
    * This changes the resting permission for that player in the server memory, but does not
    * by itself send a packet.
    *
    * \param pid The player ID.
    * \param bool The resting permission state.
    * \return void
    */
    static void SetWildernessRestAllowed(unsigned short pid, bool state);

    /**
    * \brief Set whether waiting is allowed for a player.
    *
    * This changes the waiting permission for that player in the server memory, but does not
    * by itself send a packet.
    *
    * \param pid The player ID.
    * \param bool The waiting permission state.
    * \return void
    */
    static void SetWaitAllowed(unsigned short pid, bool state);

    /**
    * \brief Send a PlayerSettings packet to the player affected by it.
    *
    * \param pid The player ID to send it to.
    * \return void
    */
    static void SendSettings(unsigned short pid) noexcept;
};

#endif //OPENMW_SETTINGSAPI_HPP
