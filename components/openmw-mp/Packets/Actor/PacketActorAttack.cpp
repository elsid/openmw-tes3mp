#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Log.hpp>
#include "PacketActorAttack.hpp"

using namespace mwmp;

PacketActorAttack::PacketActorAttack(RakNet::RakPeerInterface *peer) : ActorPacket(peer)
{
    packetID = ID_ACTOR_ATTACK;
}

void PacketActorAttack::Actor(BaseActor &actor, bool send)
{
    RW(actor.attack.target.isPlayer, send);

    if (actor.attack.target.isPlayer)
    {
        RW(actor.attack.target.guid, send);
    }
    else
    {
        RW(actor.attack.target.refId, send, true);
        RW(actor.attack.target.refNum, send);
        RW(actor.attack.target.mpNum, send);
    }

    RW(actor.attack.type, send);

    if (actor.attack.type == mwmp::Attack::ITEM_MAGIC)
        RW(actor.attack.itemId, send, true);
    else
    {
        RW(actor.attack.pressed, send);
        RW(actor.attack.success, send);

        if (actor.attack.type == mwmp::Attack::MAGIC)
        {
            RW(actor.attack.instant, send);
            RW(actor.attack.spellId, send, true);
        }
        else
        {
            RW(actor.attack.damage, send);
            RW(actor.attack.block, send);
            RW(actor.attack.knockdown, send);
            RW(actor.attack.applyWeaponEnchantment, send);
            
            if (actor.attack.type == mwmp::Attack::RANGED)
            {
                RW(actor.attack.applyProjectileEnchantment, send);
                RW(actor.attack.attackStrength, send);
            }

            if (actor.attack.success || actor.attack.applyWeaponEnchantment || actor.attack.applyProjectileEnchantment)
            {
                RW(actor.attack.hitPosition.pos[0], send);
                RW(actor.attack.hitPosition.pos[1], send);
                RW(actor.attack.hitPosition.pos[2], send);
            }
        }
    }
}
