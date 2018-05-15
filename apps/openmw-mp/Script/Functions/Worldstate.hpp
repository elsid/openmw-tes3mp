#ifndef OPENMW_WORLDSTATEAPI_HPP
#define OPENMW_WORLDSTATEAPI_HPP

#include "../Types.hpp"

#define WORLDSTATEAPI \
    {"SetHour",                     WorldstateFunctions::SetHour},\
    {"SetMonth",                    WorldstateFunctions::SetMonth},\
    {"SetDay",                      WorldstateFunctions::SetDay}

class WorldstateFunctions
{
public:

    /**
    * \brief Set the game hour for a player and send a GameTime packet to that player.
    *
    * \param pid The player ID.
    * \param hour The hour.
    * \return void
    */
    static void SetHour(unsigned short pid, double hour) noexcept;

    /**
    * \brief Set the game month for a player and send a GameTime packet to that player.
    *
    * \param pid The player ID.
    * \param month The month.
    * \return void
    */
    static void SetMonth(unsigned short pid, int month) noexcept;

    /**
    * \brief Set the game day for a player and send a GameTime packet to that player.
    *
    * \param pid The player ID.
    * \param day The day.
    * \return void
    */
    static void SetDay(unsigned short pid, int day) noexcept;

};

#endif //OPENMW_WORLDSTATEAPI_HPP
