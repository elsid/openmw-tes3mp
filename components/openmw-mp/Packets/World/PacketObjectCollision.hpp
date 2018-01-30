#ifndef OPENMW_PACKETOBJECTCOLLISION_HPP
#define OPENMW_PACKETOBJECTCOLLISION_HPP

#include <components/openmw-mp/Packets/World/WorldPacket.hpp>

namespace mwmp
{
    class PacketObjectCollision : public WorldPacket
    {
    public:
        PacketObjectCollision(RakNet::RakPeerInterface *peer);

        virtual void Object(WorldObject &worldObject, bool send);
    };
}

#endif //OPENMW_PACKETOBJECTCOLLISION_HPP
