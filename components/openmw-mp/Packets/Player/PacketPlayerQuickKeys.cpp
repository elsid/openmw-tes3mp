#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketPlayerQuickKeys.hpp"

using namespace std;
using namespace mwmp;

PacketPlayerQuickKeys::PacketPlayerQuickKeys(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_QUICKKEYS;
}

void PacketPlayerQuickKeys::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    if (send)
        player->quickKeyChanges.count = (unsigned int) (player->quickKeyChanges.quickKeys.size());
    else
        player->quickKeyChanges.quickKeys.clear();

    RW(player->quickKeyChanges.count, send);

    for (unsigned int i = 0; i < player->quickKeyChanges.count; i++)
    {
        QuickKey quickKey;

        if (send)
            quickKey = player->quickKeyChanges.quickKeys.at(i);

        RW(quickKey.type, send);
        RW(quickKey.slot, send);

        if (quickKey.type != QuickKey::UNASSIGNED)
            RW(quickKey.itemId, send);

        if (!send)
            player->quickKeyChanges.quickKeys.push_back(quickKey);
    }

}
