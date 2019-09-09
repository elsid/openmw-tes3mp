#include "PacketCellCreate.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketCellCreate::PacketCellCreate(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_PLACEHOLDER;
    orderChannel = CHANNEL_SYSTEM;
}

void PacketCellCreate::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    // Placeholder
}
