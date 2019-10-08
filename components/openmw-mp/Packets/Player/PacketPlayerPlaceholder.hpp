#ifndef OPENMW_PACKETPLACEHOLDER_HPP
#define OPENMW_PACKETPLACEHOLDER_HPP

#include <components/openmw-mp/Packets/Player/PlayerPacket.hpp>

namespace mwmp
{
    class PacketPlayerPlaceholder : public PlayerPacket
    {
    public:
        PacketPlayerPlaceholder(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETPLACEHOLDER_HPP
