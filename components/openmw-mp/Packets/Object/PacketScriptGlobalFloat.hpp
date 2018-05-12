#ifndef OPENMW_PACKETSCRIPTGLOBALFLOAT_HPP
#define OPENMW_PACKETSCRIPTGLOBALFLOAT_HPP

#include <components/openmw-mp/Packets/Object/ObjectPacket.hpp>

namespace mwmp
{
    class PacketScriptGlobalFloat : public ObjectPacket
    {
    public:
        PacketScriptGlobalFloat(RakNet::RakPeerInterface *peer);

        virtual void Object(BaseObject &baseObject, bool send);
    };
}

#endif //OPENMW_PACKETSCRIPTGLOBALFLOAT_HPP
