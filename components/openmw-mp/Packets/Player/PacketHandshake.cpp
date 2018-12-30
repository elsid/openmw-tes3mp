#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketHandshake.hpp"

using namespace mwmp;

PacketHandshake::PacketHandshake(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_HANDSHAKE;
    orderChannel = CHANNEL_SYSTEM;
}

void PacketHandshake::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    if (!RW(player->npc.mName, send, true, maxNameLength) ||
        !RW(player->serverPassword, send, true, maxPasswordLength))
    {
        packetValid = false;
        return;
    }
}
