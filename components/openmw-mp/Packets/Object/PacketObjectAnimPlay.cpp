#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectAnimPlay.hpp"

using namespace mwmp;

PacketObjectAnimPlay::PacketObjectAnimPlay(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_ANIM_PLAY;
    hasCellData = true;
}

void PacketObjectAnimPlay::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    RW(worldObject.animGroup, send);
    RW(worldObject.animMode, send);
}
