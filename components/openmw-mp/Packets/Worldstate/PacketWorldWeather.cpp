#include "PacketWorldWeather.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketWorldWeather::PacketWorldWeather(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_WORLD_WEATHER;
    orderChannel = CHANNEL_WORLDSTATE;
}

void PacketWorldWeather::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    // Placeholder to be filled in later
}
