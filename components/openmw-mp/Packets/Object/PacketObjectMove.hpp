#ifndef OPENMW_PacketObjectMove_HPP
#define OPENMW_PacketObjectMove_HPP

#include <components/openmw-mp/Packets/Object/ObjectPacket.hpp>

namespace mwmp
{
    class PacketObjectMove : public ObjectPacket
    {
    public:
        PacketObjectMove(RakNet::RakPeerInterface *peer);

        virtual void Object(WorldObject &worldObject, bool send);
    };
}

#endif //OPENMW_PacketObjectMove_HPP
