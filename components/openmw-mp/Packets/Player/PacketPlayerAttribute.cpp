#include "PacketPlayerAttribute.hpp"

#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketPlayerAttribute::PacketPlayerAttribute(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_ATTRIBUTE;
}

void PacketPlayerAttribute::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    if (send)
        player->attributeChanges.count = (unsigned int)(player->attributeChanges.attributeIndexes.size());
    else
        player->attributeChanges.attributeIndexes.clear();

    RW(player->attributeChanges.count, send);

    for (unsigned int i = 0; i < player->attributeChanges.count; i++)
    {
        int attributeId;

        if (send)
            attributeId = player->attributeChanges.attributeIndexes.at(i);

        RW(attributeId, send);

        RW(player->creatureStats.mAttributes[attributeId], send);
        RW(player->npcStats.mSkillIncrease[attributeId], send);
    }
}
