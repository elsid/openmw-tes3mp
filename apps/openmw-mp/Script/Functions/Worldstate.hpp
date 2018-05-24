#ifndef OPENMW_WORLDSTATEAPI_HPP
#define OPENMW_WORLDSTATEAPI_HPP

#include "../Types.hpp"

#define WORLDSTATEAPI \
    {"SetHour",                     WorldstateFunctions::SetHour},\
    {"SetDay",                      WorldstateFunctions::SetDay},\
    {"SetMonth",                    WorldstateFunctions::SetMonth},\
    {"SetDaysPassed",               WorldstateFunctions::SetDaysPassed},\
    {"SetTimeScale",                WorldstateFunctions::SetTimeScale},\
    \
    {"SendWorldTime",               WorldstateFunctions::SendWorldTime}

class WorldstateFunctions
{
public:

    /**
    * \brief Set the world's hour in the worldstate stored on the server.
    *
    * \param hour The hour.
    * \return void
    */
    static void SetHour(double hour) noexcept;

    /**
    * \brief Set the world's day in the worldstate stored on the server.
    *
    * \param day The day.
    * \return void
    */
    static void SetDay(int day) noexcept;

    /**
    * \brief Set the world's month in the worldstate stored on the server.
    *
    * \param month The month.
    * \return void
    */
    static void SetMonth(int month) noexcept;

    /**
    * \brief Set the world's days passed in the worldstate stored on the server.
    *
    * \param daysPassed The days passed.
    * \return void
    */
    static void SetDaysPassed(int daysPassed) noexcept;

    /**
    * \brief Set the world's time scale in the worldstate stored on the server.
    *
    * \param pid The player ID.
    * \param timeScale The time scale.
    * \return void
    */
    static void SetTimeScale(double timeScale) noexcept;

    /**
    * \brief Send a WorldTime packet with the current time and time scale
    *        to a specific player or to all players.
    *
    * \param pid The player ID.
    * \return void
    */
    static void SendWorldTime(unsigned short pid, bool toOthers = false) noexcept;

};

#endif //OPENMW_WORLDSTATEAPI_HPP
