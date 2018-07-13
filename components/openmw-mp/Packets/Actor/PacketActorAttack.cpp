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

    RW(actor.attack.spellId, send);
    RW(actor.attack.type, send);
    RW(actor.attack.success, send);
    RW(actor.attack.damage, send);

    RW(actor.attack.pressed, send);
    RW(actor.attack.knockdown, send);
    RW(actor.attack.block, send);

    RW(actor.attack.instant, send);
    RW(actor.attack.applyWeaponEnchantment, send);
    RW(actor.attack.applyProjectileEnchantment, send);
}
