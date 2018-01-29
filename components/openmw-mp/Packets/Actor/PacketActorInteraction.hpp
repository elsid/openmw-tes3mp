#ifndef OPENMW_PACKETACTORINTERACTION_HPP
#define OPENMW_PACKETACTORINTERACTION_HPP

#include <components/openmw-mp/Packets/Actor/ActorPacket.hpp>

namespace mwmp
{
    class PacketActorInteraction : public ActorPacket
    {
    public:
        PacketActorInteraction(RakNet::RakPeerInterface *peer);

        virtual void Actor(BaseActor &actor, bool send);
    };
}

#endif //OPENMW_PACKETACTORINTERACTION_HPP
