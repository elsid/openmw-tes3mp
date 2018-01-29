#ifndef OPENMW_PACKETOBJECTRESET_HPP
#define OPENMW_PACKETOBJECTRESET_HPP

#include <components/openmw-mp/Packets/World/WorldPacket.hpp>

namespace mwmp
{
    class PacketObjectReset : public WorldPacket
    {
    public:
        PacketObjectReset(RakNet::RakPeerInterface *peer);

        virtual void Object(WorldObject &worldObject, bool send);
    };
}

#endif //OPENMW_PACKETOBJECTRESET_HPP
