#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectScale.hpp"

using namespace mwmp;

PacketObjectScale::PacketObjectScale(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_SCALE;
    hasCellData = true;
}

void PacketObjectScale::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    RW(worldObject.scale, send);
}
