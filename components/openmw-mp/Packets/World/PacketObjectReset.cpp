#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectReset.hpp"

using namespace mwmp;

PacketObjectReset::PacketObjectReset(RakNet::RakPeerInterface *peer) : WorldPacket(peer)
{
    packetID = ID_OBJECT_RESET;
    hasCellData = true;
}

void PacketObjectReset::Object(WorldObject &worldObject, bool send)
{
    WorldPacket::Object(worldObject, send);
    // Placeholder
}
