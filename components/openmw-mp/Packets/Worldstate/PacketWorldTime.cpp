#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketWorldTime.hpp"

using namespace mwmp;

PacketWorldTime::PacketWorldTime(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_WORLD_TIME;
    orderChannel = CHANNEL_WORLDSTATE;
}

void PacketWorldTime::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    RW(worldstate->time.hour, send);
    RW(worldstate->time.day, send);
    RW(worldstate->time.month, send);
    RW(worldstate->time.year, send);

    RW(worldstate->time.daysPassed, send);
    RW(worldstate->time.timeScale, send);
}
