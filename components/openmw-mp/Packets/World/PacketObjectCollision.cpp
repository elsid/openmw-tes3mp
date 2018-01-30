#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectCollision.hpp"

using namespace mwmp;

PacketObjectCollision::PacketObjectCollision(RakNet::RakPeerInterface *peer) : WorldPacket(peer)
{
    packetID = ID_OBJECT_COLLISION;
    hasCellData = true;
}

void PacketObjectCollision::Object(WorldObject &worldObject, bool send)
{
    WorldPacket::Object(worldObject, send);
    // Placeholder
}
