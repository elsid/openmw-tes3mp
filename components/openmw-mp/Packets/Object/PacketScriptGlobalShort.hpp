#ifndef OPENMW_PACKETSCRIPTGLOBALSHORT_HPP
#define OPENMW_PACKETSCRIPTGLOBALSHORT_HPP

#include <components/openmw-mp/Packets/Object/ObjectPacket.hpp>

namespace mwmp
{
    class PacketScriptGlobalShort : public ObjectPacket
    {
    public:
        PacketScriptGlobalShort(RakNet::RakPeerInterface *peer);

        virtual void Object(BaseObject &baseObject, bool send);
    };
}

#endif //OPENMW_PACKETSCRIPTGLOBALSHORT_HPP
