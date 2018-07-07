#ifndef OPENMW_WORLDSTATEAPI_HPP
#define OPENMW_WORLDSTATEAPI_HPP

#include "../Types.hpp"

#define WORLDSTATEAPI \
    {"ReadLastWorldstate",                WorldstateFunctions::ReadLastWorldstate},\
    \
    {"CopyLastWorldstateToStore",         WorldstateFunctions::CopyLastWorldstateToStore},\
    \
    {"ClearMapChanges",                   WorldstateFunctions::ClearMapChanges},\
    \
    {"GetMapChangesSize",                 WorldstateFunctions::GetMapChangesSize},\
    \
    {"GetMapTileCellX",                   WorldstateFunctions::GetMapTileCellX},\
    {"GetMapTileCellY",                   WorldstateFunctions::GetMapTileCellY},\
    \
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
    {"AddEnforcedCollisionRefId",         WorldstateFunctions::AddEnforcedCollisionRefId},\
    {"ClearEnforcedCollisionRefIds",      WorldstateFunctions::ClearEnforcedCollisionRefIds},\
    \
    {"SaveMapTileImageFile",              WorldstateFunctions::SaveMapTileImageFile},\
    {"LoadMapTileImageFile",              WorldstateFunctions::LoadMapTileImageFile},\
    \
    {"SendWorldMap",                      WorldstateFunctions::SendWorldMap},\
    {"SendWorldTime",                     WorldstateFunctions::SendWorldTime},\
    {"SendWorldCollisionOverride",        WorldstateFunctions::SendWorldCollisionOverride}

class WorldstateFunctions
{
public:

    /**
    * \brief Use the last worldstate received by the server as the one being read.
    *
    * \return void
    */
    static void ReadLastWorldstate() noexcept;

    /**
    * \brief Take the contents of the read-only worldstate last received by the
    *        server from a player and move its contents to the stored worldstate
    *        that can be sent by the server.
    *
    * \return void
    */
    static void CopyLastWorldstateToStore() noexcept;

    /**
    * \brief Clear the map changes for the write-only worldstate.
    *
    * This is used to initialize the sending of new WorldMap packets.
    *
    * \return void
    */
    static void ClearMapChanges() noexcept;

    /**
    * \brief Get the number of indexes in the read worldstate's map changes.
    *
    * \return The number of indexes.
    */
    static unsigned int GetMapChangesSize() noexcept;

    /**
    * \brief Get the X coordinate of the cell corresponding to the map tile at a certain index in
    *        the read worldstate's map changes.
    *
    * \param i The index of the map tile.
    * \return The X coordinate of the cell.
    */
    static int GetMapTileCellX(unsigned int index) noexcept;

    /**
    * \brief Get the Y coordinate of the cell corresponding to the map tile at a certain index in
    *        the read worldstate's map changes.
    *
    * \param i The index of the map tile.
    * \return The Y coordinate of the cell.
    */
    static int GetMapTileCellY(unsigned int index) noexcept;

    /**
    * \brief Set the world's hour in the write-only worldstate stored on the server.
    *
    * \param hour The hour.
    * \return void
    */
    static void SetHour(double hour) noexcept;

    /**
    * \brief Set the world's day in the write-only worldstate stored on the server.
    *
    * \param day The day.
    * \return void
    */
    static void SetDay(int day) noexcept;

    /**
    * \brief Set the world's month in the write-only worldstate stored on the server.
    *
    * \param month The month.
    * \return void
    */
    static void SetMonth(int month) noexcept;

    /**
    * \brief Set the world's year in the write-only worldstate stored on the server.
    *
    * \param year The year.
    * \return void
    */
    static void SetYear(int year) noexcept;

    /**
    * \brief Set the world's days passed in the write-only worldstate stored on the server.
    *
    * \param daysPassed The days passed.
    * \return void
    */
    static void SetDaysPassed(int daysPassed) noexcept;

    /**
    * \brief Set the world's time scale in the write-only worldstate stored on the server.
    *
    * \param pid The player ID.
    * \param timeScale The time scale.
    * \return void
    */
    static void SetTimeScale(double timeScale) noexcept;

    /**
    * \brief Set the collision state for other players in the write-only worldstate stored
    *        on the server.
    *
    * \param state The collision state.
    * \return void
    */
    static void SetPlayerCollisionState(bool state) noexcept;

    /**
    * \brief Set the collision state for actors in the write-only worldstate stored on the
    *        server.
    *
    * \param state The collision state.
    * \return void
    */
    static void SetActorCollisionState(bool state) noexcept;

    /**
    * \brief Set the collision state for placed objects in the write-only worldstate stored
    *        on the server.
    *
    * \param state The collision state.
    * \return void
    */
    static void SetPlacedObjectCollisionState(bool state) noexcept;

    /**
    * \brief Whether placed objects with collision turned on should use actor collision, i.e.
    *        whether they should be slippery and prevent players from standing on them.
    *
    * \param useActorCollision Whether to use actor collision.
    * \return void
    */
    static void UseActorCollisionForPlacedObjects(bool useActorCollision) noexcept;

    /**
    * \brief Add a refId to the list of refIds for which collision should be enforced
    *        irrespective of other settings.
    *
    * \param refId The refId.
    * \return void
    */
    static void AddEnforcedCollisionRefId(const char* refId) noexcept;

    /**
    * \brief Clear the list of refIdsd for which collision should be enforced irrespective
    *        of other settings.
    *
    * \return void
    */
    static void ClearEnforcedCollisionRefIds() noexcept;

    /**
    * \brief Save the .png image data of the map tile at a certain index in the read worldstate's
    *        map changes.
    *
    * \param i The index of the map tile.
    * \param filePath The file path of the resulting file.
    * \return void
    */
    static void SaveMapTileImageFile(unsigned int index, const char *filePath) noexcept;

    /**
    * \brief Load a .png file as the image data for a map tile and add it to the write-only worldstate
    *        stored on the server.
    *
    * \param cellX The X coordinate of the cell corresponding to the map tile.
    * \param cellY The Y coordinate of the cell corresponding to the map tile.
    * \param filePath The file path of the loaded file.
    * \return void
    */
    static void LoadMapTileImageFile(int cellX, int cellY, const char* filePath) noexcept;

    /**
    * \brief Send a WorldMap packet with the current set of map changes in the write-only
    *        worldstate.
    *
    * \param pid The player ID attached to the packet.
    * \param broadcast Whether this packet should be sent only to the attached player
    *                  or to all players on the server.
    * \return void
    */
    static void SendWorldMap(unsigned short pid, bool sendToOtherPlayers = false, bool sendToAttachedPlayer = true) noexcept;

    /**
    * \brief Send a WorldTime packet with the current time and time scale in the write-only
    *        worldstate.
    *
    * \param pid The player ID attached to the packet.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param sendToAttachedPlayer Whether the packet should be sent to the player attached
    *                             to the packet (true by default).
    * \return void
    */
    static void SendWorldTime(unsigned short pid, bool sendToOtherPlayers = false, bool sendToAttachedPlayer = true) noexcept;

    /**
    * \brief Send a WorldCollisionOverride packet with the current collision overrides in
    *        the write-only worldstate.
    *
    * \param pid The player ID attached to the packet.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param sendToAttachedPlayer Whether the packet should be sent to the player attached
    *                             to the packet (true by default).
    * \return void
    */
    static void SendWorldCollisionOverride(unsigned short pid, bool sendToOtherPlayers = false, bool sendToAttachedPlayer = true) noexcept;

};

#endif //OPENMW_WORLDSTATEAPI_HPP
