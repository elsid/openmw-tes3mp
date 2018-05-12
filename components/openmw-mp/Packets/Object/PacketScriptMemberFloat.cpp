#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketScriptMemberFloat.hpp"

using namespace mwmp;

PacketScriptMemberFloat::PacketScriptMemberFloat(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_SCRIPT_MEMBER_FLOAT;
}

void PacketScriptMemberFloat::Object(BaseObject &baseObject, bool send)
{
    RW(baseObject.refId, send);
    RW(baseObject.index, send);
    RW(baseObject.floatVal, send);
}
