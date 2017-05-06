#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketMusicPlay.hpp"

using namespace mwmp;

PacketMusicPlay::PacketMusicPlay(RakNet::RakPeerInterface *peer) : WorldPacket(peer)
{
    packetID = ID_MUSIC_PLAY;
}

void PacketMusicPlay::Packet(RakNet::BitStream *bs, bool send)
{
    WorldPacket::Packet(bs, send);

    if (!send)
        event->worldObjects.clear();
    else
        event->worldObjectCount = (unsigned int)(event->worldObjects.size());

    RW(event->worldObjectCount, send);

    WorldObject worldObject;

    for (unsigned int i = 0; i < event->worldObjectCount; i++)
    {
        if (send)
        {
            worldObject = event->worldObjects.at(i);
        }

        RW(worldObject.filename, send);

        if (!send)
        {
            event->worldObjects.push_back(worldObject);
        }
    }
}
