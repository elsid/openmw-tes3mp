#ifndef OPENMW_WORLDSTATEAPI_HPP
#define OPENMW_WORLDSTATEAPI_HPP

#include "../Types.hpp"

#define WORLDSTATEAPI \
    {"SetHour",                     WorldstateFunctions::SetHour},\
    {"SetDay",                      WorldstateFunctions::SetDay},\
    {"SetMonth",                    WorldstateFunctions::SetMonth},\
    {"SetTimeScale",                WorldstateFunctions::SetTimeScale}

class WorldstateFunctions
{
public:

    /**
    * \brief Set the world's hour for a player and send a WorldTime packet to that player.
    *
    * \param pid The player ID.
    * \param hour The hour.
    * \return void
    */
    static void SetHour(unsigned short pid, double hour) noexcept;

    /**
    * \brief Set the world's day of the month for a player and send a WorldTime packet to that player.
    *
    * \param pid The player ID.
    * \param day The day.
    * \return void
    */
    static void SetDay(unsigned short pid, int day) noexcept;

    /**
    * \brief Set the world's month for a player and send a WorldTime packet to that player.
    *
    * \param pid The player ID.
    * \param month The month.
    * \return void
    */
    static void SetMonth(unsigned short pid, int month) noexcept;

    /**
    * \brief Set the world's time scale for a player and send a WorldTime packet to that player.
    *
    * \param pid The player ID.
    * \param timeScale The time scale.
    * \return void
    */
    static void SetTimeScale(unsigned short pid, double timeScale) noexcept;

};

#endif //OPENMW_WORLDSTATEAPI_HPP
