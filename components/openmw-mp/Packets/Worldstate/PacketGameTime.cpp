#include "PacketGameTime.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketGameTime::PacketGameTime(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_GAME_TIME;
    orderChannel = CHANNEL_SYSTEM;
}

void PacketGameTime::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    RW(worldstate->month, send);
    RW(worldstate->day, send);
    RW(worldstate->hour, send);
}
