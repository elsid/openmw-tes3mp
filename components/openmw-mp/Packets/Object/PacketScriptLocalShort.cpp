#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketScriptLocalShort.hpp"

using namespace mwmp;

PacketScriptLocalShort::PacketScriptLocalShort(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_SCRIPT_LOCAL_SHORT;
    hasCellData = true;
}

void PacketScriptLocalShort::Object(BaseObject &baseObject, bool send)
{
    ObjectPacket::Object(baseObject, send);
    RW(baseObject.index, send);
    RW(baseObject.shortVal, send);
}
