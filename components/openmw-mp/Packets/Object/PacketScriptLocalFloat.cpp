#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketScriptLocalFloat.hpp"

using namespace mwmp;

PacketScriptLocalFloat::PacketScriptLocalFloat(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_SCRIPT_LOCAL_FLOAT;
    hasCellData = true;
}

void PacketScriptLocalFloat::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    RW(worldObject.index, send);
    RW(worldObject.floatVal, send);
}
