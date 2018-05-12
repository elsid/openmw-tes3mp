#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketScriptLocalFloat.hpp"

using namespace mwmp;

PacketScriptLocalFloat::PacketScriptLocalFloat(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_SCRIPT_LOCAL_FLOAT;
    hasCellData = true;
}

void PacketScriptLocalFloat::Object(BaseObject &baseObject, bool send)
{
    ObjectPacket::Object(baseObject, send);
    RW(baseObject.index, send);
    RW(baseObject.floatVal, send);
}
