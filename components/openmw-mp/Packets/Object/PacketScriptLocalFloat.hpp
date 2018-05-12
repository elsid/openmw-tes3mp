#ifndef OPENMW_PACKETSCRIPTLOCALFLOAT_HPP
#define OPENMW_PACKETSCRIPTLOCALFLOAT_HPP

#include <components/openmw-mp/Packets/Object/ObjectPacket.hpp>

namespace mwmp
{
    class PacketScriptLocalFloat : public ObjectPacket
    {
    public:
        PacketScriptLocalFloat(RakNet::RakPeerInterface *peer);

        virtual void Object(WorldObject &worldObject, bool send);
    };
}

#endif //OPENMW_PACKETSCRIPTLOCALFLOAT_HPP
