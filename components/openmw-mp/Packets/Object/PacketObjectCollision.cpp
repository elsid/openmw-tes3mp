#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectCollision.hpp"

using namespace mwmp;

PacketObjectCollision::PacketObjectCollision(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_COLLISION;
    hasCellData = true;
}

void PacketObjectCollision::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    // Placeholder
}
