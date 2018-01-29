#include "PacketCellCreate.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketCellCreate::PacketCellCreate(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_CELL_CREATE;
    orderChannel = CHANNEL_SYSTEM;
}

void PacketCellCreate::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    // Placeholder
}
