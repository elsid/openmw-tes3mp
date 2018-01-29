#ifndef OPENMW_PACKETSCRIPTGLOBALFLOAT_HPP
#define OPENMW_PACKETSCRIPTGLOBALFLOAT_HPP

#include <components/openmw-mp/Packets/World/WorldPacket.hpp>

namespace mwmp
{
    class PacketScriptGlobalFloat : public WorldPacket
    {
    public:
        PacketScriptGlobalFloat(RakNet::RakPeerInterface *peer);

        virtual void Object(WorldObject &worldObject, bool send);
    };
}

#endif //OPENMW_PACKETSCRIPTGLOBALFLOAT_HPP
