#ifndef OPENMW_PACKETOBJECTCOLLISION_HPP
#define OPENMW_PACKETOBJECTCOLLISION_HPP

#include <components/openmw-mp/Packets/Object/ObjectPacket.hpp>

namespace mwmp
{
    class PacketObjectCollision : public ObjectPacket
    {
    public:
        PacketObjectCollision(RakNet::RakPeerInterface *peer);

        virtual void Object(BaseObject &baseObject, bool send);
    };
}

#endif //OPENMW_PACKETOBJECTCOLLISION_HPP
