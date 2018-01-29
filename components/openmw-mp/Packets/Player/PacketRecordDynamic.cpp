#include "PacketRecordDynamic.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketRecordDynamic::PacketRecordDynamic(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_RECORD_DYNAMIC;
    orderChannel = CHANNEL_SYSTEM;
}

void PacketRecordDynamic::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    // Placeholder
}
