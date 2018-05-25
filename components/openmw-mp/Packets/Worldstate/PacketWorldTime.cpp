#include "PacketWorldTime.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketWorldTime::PacketWorldTime(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_WORLD_TIME;
    orderChannel = CHANNEL_WORLDSTATE;
}

void PacketWorldTime::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    RW(worldstate->hour, send);
    RW(worldstate->day, send);
    RW(worldstate->month, send);
    RW(worldstate->year, send);

    RW(worldstate->daysPassed, send);
    RW(worldstate->timeScale, send);
}
