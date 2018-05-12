#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectAttach.hpp"

using namespace mwmp;

PacketObjectAttach::PacketObjectAttach(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_ATTACH;
    hasCellData = true;
}

void PacketObjectAttach::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    // Placeholder
}
