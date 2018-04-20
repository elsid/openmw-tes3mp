#include "PacketPlayerEquipment.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketPlayerEquipment::PacketPlayerEquipment(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_EQUIPMENT;
}

void PacketPlayerEquipment::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    uint32_t count;
    if (send)
        count = static_cast<uint32_t>(player->equipmentIndexChanges.size());

    RW(count, send);

    if (!send)
    {
        player->equipmentIndexChanges.clear();
        player->equipmentIndexChanges.resize(count);
    }

    for (auto &&equipmentIndex : player->equipmentIndexChanges)
    {
        RW(equipmentIndex, send);

        RW(player->equipmentItems[equipmentIndex].refId, send);
        RW(player->equipmentItems[equipmentIndex].count, send);
        RW(player->equipmentItems[equipmentIndex].charge, send);
        RW(player->equipmentItems[equipmentIndex].enchantmentCharge, send);
    }
}
