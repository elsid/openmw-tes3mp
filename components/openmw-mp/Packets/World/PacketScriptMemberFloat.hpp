#ifndef OPENMW_PACKETSCRIPTMEMBERFLOAT_HPP
#define OPENMW_PACKETSCRIPTMEMBERFLOAT_HPP

#include <components/openmw-mp/Packets/World/WorldPacket.hpp>

namespace mwmp
{
    class PacketScriptMemberFloat : public WorldPacket
    {
    public:
        PacketScriptMemberFloat(RakNet::RakPeerInterface *peer);

        virtual void Object(WorldObject &obj, bool send);
    };
}

#endif //OPENMW_PACKETSCRIPTMEMBERFLOAT_HPP
