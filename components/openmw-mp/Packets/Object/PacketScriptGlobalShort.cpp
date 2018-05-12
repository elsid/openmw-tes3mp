#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketScriptGlobalShort.hpp"

using namespace mwmp;

PacketScriptGlobalShort::PacketScriptGlobalShort(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_SCRIPT_GLOBAL_SHORT;
}

void PacketScriptGlobalShort::Object(BaseObject &baseObject, bool send)
{
    RW(baseObject.varName, send);
    RW(baseObject.shortVal, send);
}
