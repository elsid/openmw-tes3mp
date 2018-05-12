#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectState.hpp"

using namespace mwmp;

PacketObjectState::PacketObjectState(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_STATE;
    hasCellData = true;
}

void PacketObjectState::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    RW(worldObject.objectState, send);
}
