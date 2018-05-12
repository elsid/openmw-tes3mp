#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectTrap.hpp"

using namespace mwmp;

PacketObjectTrap::PacketObjectTrap(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_TRAP;
    hasCellData = true;
}

void PacketObjectTrap::Object(WorldObject &worldObject, bool send)
{
    ObjectPacket::Object(worldObject, send);
    RW(worldObject.isDisarmed, send);

    if (!worldObject.isDisarmed)
        RW(worldObject.position, send);
}
