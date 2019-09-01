#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectHit.hpp"

using namespace mwmp;

PacketObjectHit::PacketObjectHit(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_HIT;
    hasCellData = true;
}

void PacketObjectHit::Object(BaseObject &baseObject, bool send)
{
    ObjectPacket::Object(baseObject, send);
    // Placeholder
}
