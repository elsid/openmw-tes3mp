#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketScriptLocalShort.hpp"

using namespace mwmp;

PacketScriptLocalShort::PacketScriptLocalShort(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_SCRIPT_LOCAL_SHORT;
    hasCellData = true;
}

void PacketScriptLocalShort::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    RW(worldObject.index, send);
    RW(worldObject.shortVal, send);
}
