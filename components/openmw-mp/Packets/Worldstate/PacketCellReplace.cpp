#include "PacketCellReplace.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketCellReplace::PacketCellReplace(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_CELL_REPLACE;
    orderChannel = CHANNEL_SYSTEM;
}

void PacketCellReplace::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    // Placeholder
}
