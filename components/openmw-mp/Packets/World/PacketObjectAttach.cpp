#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectAttach.hpp"

using namespace mwmp;

PacketObjectAttach::PacketObjectAttach(RakNet::RakPeerInterface *peer) : WorldPacket(peer)
{
    packetID = ID_OBJECT_ATTACH;
    hasCellData = true;
}

void PacketObjectAttach::Object(WorldObject &worldObject, bool send)
{
    WorldPacket::Object(worldObject, send);
    // Placeholder
}
