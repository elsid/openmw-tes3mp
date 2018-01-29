#ifndef OPENMW_PACKETDOORDESTINATION_HPP
#define OPENMW_PACKETDOORDESTINATION_HPP

#include <components/openmw-mp/Packets/World/WorldPacket.hpp>

namespace mwmp
{
    class PacketDoorDestination : public WorldPacket
    {
    public:
        PacketDoorDestination(RakNet::RakPeerInterface *peer);

        virtual void Object(WorldObject &worldObject, bool send);
    };
}

#endif //OPENMW_PACKETDOORDESTINATION_HPP
