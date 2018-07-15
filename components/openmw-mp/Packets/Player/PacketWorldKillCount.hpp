#ifndef OPENMW_PACKETWORLDKILLCOUNT_HPP
#define OPENMW_PACKETWORLDKILLCOUNT_HPP

#include <components/openmw-mp/Packets/Player/PlayerPacket.hpp>

namespace mwmp
{
    class PacketWorldKillCount : public PlayerPacket
    {
    public:
        PacketWorldKillCount(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETWORLDKILLCOUNT_HPP
