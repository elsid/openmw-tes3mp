#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketConsoleCommand.hpp"

using namespace mwmp;

PacketConsoleCommand::PacketConsoleCommand(RakNet::RakPeerInterface *peer) : WorldPacket(peer)
{
    packetID = ID_CONSOLE_COMMAND;
}

void PacketConsoleCommand::Packet(RakNet::BitStream *bs, bool send)
{
    if (!PacketHeader(bs, send))
        return;

    RW(event->consoleCommand, send);

    WorldObject worldObject;
    for (unsigned int i = 0; i < event->worldObjectCount; i++)
    {
        if (send)
            worldObject = event->worldObjects.at(i);

        RW(worldObject.isPlayer, send);

        if (worldObject.isPlayer)
            RW(worldObject.guid, send);
        else
            Object(worldObject, send);

        if (!send)
            event->worldObjects.push_back(worldObject);
    }
}
