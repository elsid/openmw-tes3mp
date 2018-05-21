#ifndef OPENMW_PACKETGAMETIME_HPP
#define OPENMW_PACKETGAMETIME_HPP

#include <components/openmw-mp/Packets/Worldstate/WorldstatePacket.hpp>

namespace mwmp
{
    class PacketGameTime : public WorldstatePacket
    {
    public:
        PacketGameTime(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETGAMETIME_HPP
