#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketScriptGlobalFloat.hpp"

using namespace mwmp;

PacketScriptGlobalFloat::PacketScriptGlobalFloat(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_SCRIPT_GLOBAL_FLOAT;
}

void PacketScriptGlobalFloat::Object(WorldObject &worldObject, bool send)
{
    RW(worldObject.varName, send);
    RW(worldObject.floatVal, send);
}
