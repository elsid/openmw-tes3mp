#ifndef OPENMW_WORLDSTATEAPI_HPP
#define OPENMW_WORLDSTATEAPI_HPP

#include "../Types.hpp"

#define WORLDSTATEAPI \
    {"SetHour",                           WorldstateFunctions::SetHour},\
    {"SetDay",                            WorldstateFunctions::SetDay},\
    {"SetMonth",                          WorldstateFunctions::SetMonth},\
    {"SetYear",                           WorldstateFunctions::SetYear},\
    {"SetDaysPassed",                     WorldstateFunctions::SetDaysPassed},\
    {"SetTimeScale",                      WorldstateFunctions::SetTimeScale},\
    \
    {"SetPlayerCollisionState",           WorldstateFunctions::SetPlayerCollisionState},\
    {"SetActorCollisionState",            WorldstateFunctions::SetActorCollisionState},\
    {"SetPlacedObjectCollisionState",     WorldstateFunctions::SetPlacedObjectCollisionState},\
    {"UseActorCollisionForPlacedObjects", WorldstateFunctions::UseActorCollisionForPlacedObjects},\
    \
    {"SendWorldTime",                     WorldstateFunctions::SendWorldTime},\
    {"SendWorldCollisionOverride",        WorldstateFunctions::SendWorldCollisionOverride}

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
    * \brief Set the world's year in the worldstate stored on the server.
    *
    * \param year The year.
    * \return void
    */
    static void SetYear(int year) noexcept;

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
    * \brief Set the collision state for other players.
    *
    * \param state The collision state.
    * \return void
    */
    static void SetPlayerCollisionState(bool state) noexcept;

    /**
    * \brief Set the collision state for actors.
    *
    * \param state The collision state.
    * \return void
    */
    static void SetActorCollisionState(bool state) noexcept;

    /**
    * \brief Set the collision state for placed objects.
    *
    * \param state The collision state.
    * \return void
    */
    static void SetPlacedObjectCollisionState(bool state) noexcept;

    /**
    * \brief Whether placed objects with collision turned on should use
    *        actor collision, i.e. whether they should be slippery
    *        and prevent players from standing on them.
    *
    * \param useActorCollision Whether to use actor collision.
    * \return void
    */
    static void UseActorCollisionForPlacedObjects(bool useActorCollision) noexcept;

    /**
    * \brief Send a WorldTime packet with the current time and time scale
    *        to a specific player or to all players.
    *
    * \param pid The player ID.
    * \return void
    */
    static void SendWorldTime(unsigned short pid, bool toOthers = false) noexcept;

    /**
    * \brief Send a WorldCollisionOverride packet with the current collision overrides
    *        to a specific player or to all players.
    *
    * \param pid The player ID.
    * \return void
    */
    static void SendWorldCollisionOverride(unsigned short pid, bool toOthers = false) noexcept;

};

#endif //OPENMW_WORLDSTATEAPI_HPP
