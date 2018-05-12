#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketDoorDestination.hpp"

using namespace mwmp;

PacketDoorDestination::PacketDoorDestination(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_DOOR_DESTINATION;
    hasCellData = true;
}

void PacketDoorDestination::Object(BaseObject &baseObject, bool send)
{
    ObjectPacket::Object(baseObject, send);

    RW(baseObject.teleportState, send);

    if (baseObject.teleportState)
    {
        RW(baseObject.destinationCell.mData, send, 1);
        RW(baseObject.destinationCell.mName, send, 1);

        RW(baseObject.destinationPosition.pos, send, 1);
        RW(baseObject.destinationPosition.rot[0], send, 1);
        RW(baseObject.destinationPosition.rot[2], send, 1);
    }
}
