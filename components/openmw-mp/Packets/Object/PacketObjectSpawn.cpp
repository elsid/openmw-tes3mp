#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectSpawn.hpp"

using namespace mwmp;

PacketObjectSpawn::PacketObjectSpawn(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_SPAWN;
    hasCellData = true;
}

void PacketObjectSpawn::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    RW(worldObject.position, send);

    RW(worldObject.hasMaster, send);

    if (worldObject.hasMaster)
    {
        RW(worldObject.master.isPlayer, send);

        if (worldObject.master.isPlayer)
        {
            RW(worldObject.master.guid, send);
        }
        else
        {
            RW(worldObject.master.refId, send, 1);
            RW(worldObject.master.refNumIndex, send);
            RW(worldObject.master.mpNum, send);
        }
    }
}
