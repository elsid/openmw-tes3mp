#ifndef OPENMW_PACKETOBJECTATTACH_HPP
#define OPENMW_PACKETOBJECTATTACH_HPP

#include <components/openmw-mp/Packets/World/WorldPacket.hpp>

namespace mwmp
{
    class PacketObjectAttach : public WorldPacket
    {
    public:
        PacketObjectAttach(RakNet::RakPeerInterface *peer);

        virtual void Object(WorldObject &worldObject, bool send);
    };
}

#endif //OPENMW_PACKETOBJECTATTACH_HPP
