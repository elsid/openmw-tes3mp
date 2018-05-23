#include "PacketRecordDynamic.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketRecordDynamic::PacketRecordDynamic(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_RECORD_DYNAMIC;
    orderChannel = CHANNEL_WORLDSTATE;
}

void PacketRecordDynamic::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    // Placeholder
}
