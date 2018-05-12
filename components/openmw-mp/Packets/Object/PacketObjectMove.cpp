#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectMove.hpp"

using namespace mwmp;

PacketObjectMove::PacketObjectMove(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_MOVE;
    hasCellData = true;
}

void PacketObjectMove::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    RW(worldObject.position.pos, send);
}
