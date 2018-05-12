#ifndef OPENMW_PACKETSCRIPTMEMBERFLOAT_HPP
#define OPENMW_PACKETSCRIPTMEMBERFLOAT_HPP

#include <components/openmw-mp/Packets/Object/ObjectPacket.hpp>

namespace mwmp
{
    class PacketScriptMemberFloat : public ObjectPacket
    {
    public:
        PacketScriptMemberFloat(RakNet::RakPeerInterface *peer);

        virtual void Object(BaseObject &obj, bool send);
    };
}

#endif //OPENMW_PACKETSCRIPTMEMBERFLOAT_HPP
