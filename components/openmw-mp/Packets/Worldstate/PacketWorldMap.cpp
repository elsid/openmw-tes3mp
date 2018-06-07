#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketWorldMap.hpp"

using namespace std;
using namespace mwmp;

PacketWorldMap::PacketWorldMap(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_WORLD_MAP;
}

void PacketWorldMap::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    uint32_t changesCount;

    if (send)
        changesCount = static_cast<uint32_t>(worldstate->mapChanges.mapTiles.size());

    RW(changesCount, send);

    if (!send)
    {
        worldstate->mapChanges.mapTiles.clear();
        worldstate->mapChanges.mapTiles.resize(changesCount);
    }

    for (auto &&mapTile : worldstate->mapChanges.mapTiles)
    {
        RW(mapTile.x, send);
        RW(mapTile.y, send);

        uint32_t imageDataCount;

        if (send)
            imageDataCount = static_cast<uint32_t>(mapTile.imageData.size());

        RW(imageDataCount, send);

        if (!send)
        {
            mapTile.imageData.clear();
            mapTile.imageData.resize(imageDataCount);
        }

        for (auto &&imageChar : mapTile.imageData)
        {
            RW(imageChar, send);
        }
    }
}
