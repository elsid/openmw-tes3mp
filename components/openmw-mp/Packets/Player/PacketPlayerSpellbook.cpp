#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketPlayerSpellbook.hpp"

using namespace std;
using namespace mwmp;

PacketPlayerSpellbook::PacketPlayerSpellbook(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_SPELLBOOK;
}

void PacketPlayerSpellbook::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    RW(player->spellbookChanges.action, send);

    if (send)
        player->spellbookChanges.count = (unsigned int) (player->spellbookChanges.spells.size());
    else
        player->spellbookChanges.spells.clear();

    RW(player->spellbookChanges.count, send);

    for (unsigned int i = 0; i < player->spellbookChanges.count; i++)
    {
        ESM::Spell spell;

        if (send)
            spell = player->spellbookChanges.spells.at(i);

        RW(spell.mId, send, true);

        if(spell.mId.find("$dynamic") != string::npos)
        {
            RW(spell.mName, send, true);

            RW(spell.mData.mType, send, true);
            RW(spell.mData.mCost, send, true);
            RW(spell.mData.mFlags, send, true);

            int effectCount = 0;
            if (send)
                effectCount = spell.mEffects.mList.size();

            RW(effectCount, send, true);

            for (unsigned int j = 0; j < effectCount; j++)
            {
                ESM::ENAMstruct effect;
                if (send)
                    effect = spell.mEffects.mList.at(j);

                RW(effect.mEffectID, send, true);
                RW(effect.mSkill, send, true);
                RW(effect.mAttribute, send, true);
                RW(effect.mRange, send, true);
                RW(effect.mArea, send, true);
                RW(effect.mDuration, send, true);
                RW(effect.mMagnMin, send, true);
                RW(effect.mMagnMax, send, true);

                if(!send)
                    spell.mEffects.mList.push_back(effect);
            }
        }

        if (!send)
            player->spellbookChanges.spells.push_back(spell);
    }

}
