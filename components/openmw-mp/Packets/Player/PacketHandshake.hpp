#ifndef OPENMW_PACKETHANDSHAKE_HPP
#define OPENMW_PACKETHANDSHAKE_HPP

#include <components/openmw-mp/Packets/Player/PlayerPacket.hpp>

namespace mwmp
{
    class PacketHandshake : public PlayerPacket
    {
    public:
        PacketHandshake(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);

        const static uint32_t maxNameLength = 256;
        const static uint32_t maxPasswordLength = 256;
    };
}

#endif //OPENMW_PACKETHANDSHAKE_HPP
