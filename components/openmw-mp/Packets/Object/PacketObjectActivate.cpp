#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectActivate.hpp"

using namespace mwmp;

PacketObjectActivate::PacketObjectActivate(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_ACTIVATE;
    hasCellData = true;
}

void PacketObjectActivate::Object(BaseObject &baseObject, bool send)
{
    ObjectPacket::Object(baseObject, send);
}
