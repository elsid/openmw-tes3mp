#ifndef OPENMW_PACKETSCRIPTLOCALSHORT_HPP
#define OPENMW_PACKETSCRIPTLOCALSHORT_HPP

#include <components/openmw-mp/Packets/Object/ObjectPacket.hpp>

namespace mwmp
{
    class PacketScriptLocalShort : public ObjectPacket
    {
    public:
        PacketScriptLocalShort(RakNet::RakPeerInterface *peer);

        virtual void Object(BaseObject &obj, bool send);
    };
}

#endif //OPENMW_PACKETSCRIPTLOCALSHORT_HPP
