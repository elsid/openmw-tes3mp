#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketDoorDestination.hpp"

using namespace mwmp;

PacketDoorDestination::PacketDoorDestination(RakNet::RakPeerInterface *peer) : WorldPacket(peer)
{
    packetID = ID_DOOR_DESTINATION;
    hasCellData = true;
}

void PacketDoorDestination::Object(WorldObject &worldObject, bool send)
{
    WorldPacket::Object(worldObject, send);

    RW(worldObject.teleportState, send);

    if (worldObject.teleportState)
    {
        RW(worldObject.destinationCell.mData, send, 1);
        RW(worldObject.destinationCell.mName, send, 1);

        RW(worldObject.destinationPosition.pos, send, 1);
        RW(worldObject.destinationPosition.rot[0], send, 1);
        RW(worldObject.destinationPosition.rot[2], send, 1);
    }
}
