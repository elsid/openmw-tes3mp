#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Log.hpp>
#include "PacketActorAI.hpp"

using namespace mwmp;

PacketActorAI::PacketActorAI(RakNet::RakPeerInterface *peer) : ActorPacket(peer)
{
    packetID = ID_ACTOR_AI;
}

void PacketActorAI::Actor(BaseActor &actor, bool send)
{
    RW(actor.aiAction, send);
    RW(actor.hasAiTarget, send);

    if (actor.hasAiTarget)
    {
        RW(actor.aiTarget.isPlayer, send);

        if (actor.aiTarget.isPlayer)
        {
            RW(actor.aiTarget.guid, send);
        }
        else
        {
            RW(actor.aiTarget.refId, send, 1);
            RW(actor.aiTarget.refNumIndex, send);
            RW(actor.aiTarget.mpNum, send);
        }
    }
}
