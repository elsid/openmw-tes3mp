#include "../Packets/Worldstate/PacketGameTime.hpp"

#include "WorldstatePacketController.hpp"

template <typename T>
inline void AddPacket(mwmp::WorldstatePacketController::packets_t *packets, RakNet::RakPeerInterface *peer)
{
    T *packet = new T(peer);
    typedef mwmp::WorldstatePacketController::packets_t::value_type value_t;
    packets->insert(value_t(packet->GetPacketID(), value_t::second_type(packet)));
}

mwmp::WorldstatePacketController::WorldstatePacketController(RakNet::RakPeerInterface *peer)
{
    AddPacket<PacketGameTime>(&packets, peer);
}


mwmp::WorldstatePacket *mwmp::WorldstatePacketController::GetPacket(RakNet::MessageID id)
{
    return packets[(unsigned char)id].get();
}

void mwmp::WorldstatePacketController::SetStream(RakNet::BitStream *inStream, RakNet::BitStream *outStream)
{
    for(const auto &packet : packets)
        packet.second->SetStreams(inStream, outStream);
}

bool mwmp::WorldstatePacketController::ContainsPacket(RakNet::MessageID id)
{
    for(const auto &packet : packets)
    {
        if (packet.first == id)
            return true;
    }
    return false;
}
