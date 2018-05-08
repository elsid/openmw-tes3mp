#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketPlayerMap.hpp"

using namespace std;
using namespace mwmp;

PacketPlayerMap::PacketPlayerMap(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_MAP;
}

void PacketPlayerMap::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    uint32_t changesCount;

    if (send)
        changesCount = static_cast<uint32_t>(player->mapChanges.mapTiles.size());

    RW(changesCount, send);

    if (!send)
    {
        player->mapChanges.mapTiles.clear();
        player->mapChanges.mapTiles.resize(changesCount);
    }

    for (auto &&mapTile : player->mapChanges.mapTiles)
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
