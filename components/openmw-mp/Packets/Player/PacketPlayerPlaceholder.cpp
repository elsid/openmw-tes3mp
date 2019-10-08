#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketPlayerPlaceholder.hpp"

mwmp::PacketPlayerPlaceholder::PacketPlayerPlaceholder(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLACEHOLDER;
}

void mwmp::PacketPlayerPlaceholder::Packet(RakNet::BitStream *bs, bool send)
{
    // Placeholder
}
