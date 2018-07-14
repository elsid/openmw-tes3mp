#ifndef OPENMW_PACKETCELLCREATE_HPP
#define OPENMW_PACKETCELLCREATE_HPP

#include <components/openmw-mp/Packets/Worldstate/WorldstatePacket.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

namespace mwmp
{
    class PacketCellCreate: public WorldstatePacket
    {
    public:
        PacketCellCreate(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETCELLCREATE_HPP
