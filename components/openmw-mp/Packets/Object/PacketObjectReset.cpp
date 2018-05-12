#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectReset.hpp"

using namespace mwmp;

PacketObjectReset::PacketObjectReset(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_RESET;
    hasCellData = true;
}

void PacketObjectReset::Object(BaseObject &baseObject, bool send)
{
    ObjectPacket::Object(baseObject, send);
    // Placeholder
}
