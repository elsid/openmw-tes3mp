#ifndef OPENMW_PACKETOBJECTACTIVATE_HPP
#define OPENMW_PACKETOBJECTACTIVATE_HPP

#include <components/openmw-mp/Packets/Object/ObjectPacket.hpp>

namespace mwmp
{
    class PacketObjectActivate : public ObjectPacket
    {
    public:
        PacketObjectActivate(RakNet::RakPeerInterface *peer);

        virtual void Object(BaseObject &baseObject, bool send);
    };
}

#endif //OPENMW_PACKETOBJECTACTIVATE_HPP
