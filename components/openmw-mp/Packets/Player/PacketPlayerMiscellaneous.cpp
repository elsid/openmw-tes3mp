#include "PacketPlayerMiscellaneous.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketPlayerMiscellaneous::PacketPlayerMiscellaneous(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_MISCELLANEOUS;
}

void PacketPlayerMiscellaneous::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    RW(player->miscellaneousChangeType, send);

    if (player->miscellaneousChangeType == mwmp::MISCELLANEOUS_CHANGE_TYPE::MARK_LOCATION)
    {
        RW(player->markCell.mData, send, 1);
        RW(player->markCell.mName, send, 1);

        RW(player->markPosition.pos, send);
        RW(player->markPosition.rot[0], send);
        RW(player->markPosition.rot[2], send);
    }
}
