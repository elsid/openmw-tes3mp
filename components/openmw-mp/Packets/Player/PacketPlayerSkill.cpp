#include "PacketPlayerSkill.hpp"

#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/esm/creaturestats.hpp>

using namespace mwmp;

PacketPlayerSkill::PacketPlayerSkill(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_SKILL;
}

void PacketPlayerSkill::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    if (send)
        player->skillChanges.count = (unsigned int)(player->skillChanges.skillIndexes.size());
    else
        player->skillChanges.skillIndexes.clear();

    RW(player->skillChanges.count, send);

    for (unsigned int i = 0; i < player->skillChanges.count; i++)
    {
        int skillId;

        if (send)
            skillId = player->skillChanges.skillIndexes.at(i);

        RW(skillId, send);

        RW(player->npcStats.mSkills[skillId], send);
    }
}
