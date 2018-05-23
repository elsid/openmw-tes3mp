#ifndef OPENMW_PACKETRECORDDYNAMIC_HPP
#define OPENMW_PACKETRECORDDYNAMIC_HPP

#include <components/openmw-mp/Packets/Worldstate/WorldstatePacket.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

namespace mwmp
{
    class PacketRecordDynamic: public WorldstatePacket
    {
    public:
        PacketRecordDynamic(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETRECORDDYNAMIC_HPP
