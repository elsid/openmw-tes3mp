#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketScriptMemberFloat.hpp"

using namespace mwmp;

PacketScriptMemberFloat::PacketScriptMemberFloat(RakNet::RakPeerInterface *peer) : WorldPacket(peer)
{
    packetID = ID_SCRIPT_MEMBER_FLOAT;
}

void PacketScriptMemberFloat::Object(WorldObject &worldObject, bool send)
{
    RW(worldObject.refId, send);
    RW(worldObject.index, send);
    RW(worldObject.floatVal, send);
}
