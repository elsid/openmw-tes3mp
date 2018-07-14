#ifndef OPENMW_PACKETCELLREPLACE_HPP
#define OPENMW_PACKETCELLREPLACE_HPP

#include <components/openmw-mp/Packets/Worldstate/WorldstatePacket.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

namespace mwmp
{
    class PacketCellReplace: public WorldstatePacket
    {
    public:
        PacketCellReplace(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETCELLREPLACE_HPP
