#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Base/BaseWorldstate.hpp>

#include <apps/openmw-mp/Networking.hpp>
#include <apps/openmw-mp/Player.hpp>
#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <fstream>

#include "Worldstate.hpp"

using namespace std;
using namespace mwmp;

BaseWorldstate writeWorldstate;
BaseWorldstate *readWorldstate;

void WorldstateFunctions::ReadLastWorldstate() noexcept
{
    readWorldstate = mwmp::Networking::getPtr()->getLastWorldstate();
}

void WorldstateFunctions::CopyLastWorldstateToStore() noexcept
{
    writeWorldstate = *readWorldstate;
}

void WorldstateFunctions::ClearMapChanges() noexcept
{
    writeWorldstate.mapChanges.mapTiles.clear();
}

unsigned int WorldstateFunctions::GetMapChangesSize() noexcept
{
    return readWorldstate->mapChanges.mapTiles.size();
}

int WorldstateFunctions::GetMapTileCellX(unsigned int index) noexcept
{
    return readWorldstate->mapChanges.mapTiles.at(index).x;
}

int WorldstateFunctions::GetMapTileCellY(unsigned int index) noexcept
{
    return readWorldstate->mapChanges.mapTiles.at(index).y;
}

void WorldstateFunctions::SetHour(double hour) noexcept
{
    writeWorldstate.hour = hour;
}

void WorldstateFunctions::SetDay(int day) noexcept
{
    writeWorldstate.day = day;
}

void WorldstateFunctions::SetMonth(int month) noexcept
{
    writeWorldstate.month = month;
}

void WorldstateFunctions::SetYear(int year) noexcept
{
    writeWorldstate.year = year;
}

void WorldstateFunctions::SetDaysPassed(int daysPassed) noexcept
{
    writeWorldstate.daysPassed = daysPassed;
}

void WorldstateFunctions::SetTimeScale(double timeScale) noexcept
{
    writeWorldstate.timeScale = timeScale;
}

void WorldstateFunctions::SetPlayerCollisionState(bool state) noexcept
{
    writeWorldstate.hasPlayerCollision = state;
}

void WorldstateFunctions::SetActorCollisionState(bool state) noexcept
{
    writeWorldstate.hasActorCollision = state;
}

void WorldstateFunctions::SetPlacedObjectCollisionState(bool state) noexcept
{
    writeWorldstate.hasPlacedObjectCollision = state;
}

void WorldstateFunctions::UseActorCollisionForPlacedObjects(bool useActorCollision) noexcept
{
    writeWorldstate.useActorCollisionForPlacedObjects = useActorCollision;
}

void WorldstateFunctions::AddEnforcedCollisionRefId(const char *refId) noexcept
{
    writeWorldstate.enforcedCollisionRefIds.push_back(refId);
}

void WorldstateFunctions::ClearEnforcedCollisionRefIds() noexcept
{
    writeWorldstate.enforcedCollisionRefIds.clear();
}

void WorldstateFunctions::SaveMapTileImageFile(unsigned int index, const char *filePath) noexcept
{
    if (index >= readWorldstate->mapChanges.mapTiles.size())
        return;

    const std::vector<char>& imageData = readWorldstate->mapChanges.mapTiles.at(index).imageData;

    std::ofstream outputFile(filePath, std::ios::binary);
    std::ostream_iterator<char> outputIterator(outputFile);
    std::copy(imageData.begin(), imageData.end(), outputIterator);
}

void WorldstateFunctions::LoadMapTileImageFile(int cellX, int cellY, const char* filePath) noexcept
{
    mwmp::MapTile mapTile;
    mapTile.x = cellX;
    mapTile.y = cellY;

    std::ifstream inputFile(filePath, std::ios::binary);
    mapTile.imageData = std::vector<char>(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>());

    if (mapTile.imageData.size() > mwmp::maxImageDataSize)
    {
        LOG_MESSAGE_SIMPLE(Log::LOG_ERROR, "Error loading image file for map tile: "
            "%s has a size of %i, which is over the maximum allowed of %i!",
            filePath, mapTile.imageData.size(), mwmp::maxImageDataSize);
    }
    else
    {
        writeWorldstate.mapChanges.mapTiles.push_back(mapTile);
    }
}

void WorldstateFunctions::SendWorldMap(unsigned short pid, bool sendToOtherPlayers, bool sendToAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeWorldstate.guid = player->guid;

    mwmp::WorldstatePacket *packet = mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_WORLD_MAP);
    packet->setWorldstate(&writeWorldstate);

    if (sendToAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

void WorldstateFunctions::SendWorldTime(unsigned short pid, bool sendToOtherPlayers, bool sendToAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeWorldstate.guid = player->guid;

    mwmp::WorldstatePacket *packet = mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_WORLD_TIME);
    packet->setWorldstate(&writeWorldstate);
    
    if (sendToAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

void WorldstateFunctions::SendWorldCollisionOverride(unsigned short pid, bool sendToOtherPlayers, bool sendToAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeWorldstate.guid = player->guid;

    mwmp::WorldstatePacket *packet = mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_WORLD_COLLISION_OVERRIDE);
    packet->setWorldstate(&writeWorldstate);

    if (sendToAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}
