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
    // Placeholder
}
