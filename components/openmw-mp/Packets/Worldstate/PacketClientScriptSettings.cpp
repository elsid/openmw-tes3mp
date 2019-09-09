#include "PacketClientScriptSettings.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketClientScriptSettings::PacketClientScriptSettings(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_CLIENT_SCRIPT_SETTINGS;
    orderChannel = CHANNEL_WORLDSTATE;
}

void PacketClientScriptSettings::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    uint32_t clientScriptsCount;

    if (send)
        clientScriptsCount = static_cast<uint32_t>(worldstate->synchronizedClientScriptIds.size());

    RW(clientScriptsCount, send);

    if (!send)
    {
        worldstate->synchronizedClientScriptIds.clear();
        worldstate->synchronizedClientScriptIds.resize(clientScriptsCount);
    }

    for (auto &&clientScriptId : worldstate->synchronizedClientScriptIds)
    {
        RW(clientScriptId, send);
    }
}
