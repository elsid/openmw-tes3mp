#ifndef OPENMW_PACKETPLAYERINTERACTION_HPP
#define OPENMW_PACKETPLAYERINTERACTION_HPP

#include <components/openmw-mp/Packets/Player/PlayerPacket.hpp>

namespace mwmp
{
    class PacketPlayerInteraction : public PlayerPacket
    {
    public:
        PacketPlayerInteraction(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETPLAYERINTERACTION_HPP
