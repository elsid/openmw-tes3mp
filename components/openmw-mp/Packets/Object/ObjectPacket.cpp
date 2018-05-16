#include <components/openmw-mp/NetworkMessages.hpp>
#include <PacketPriority.h>
#include <RakPeer.h>
#include "ObjectPacket.hpp"

using namespace mwmp;

ObjectPacket::ObjectPacket(RakNet::RakPeerInterface *peer) : BasePacket(peer)
{
    hasCellData = false;
    packetID = 0;
    priority = HIGH_PRIORITY;
    reliability = RELIABLE_ORDERED;
    orderChannel = CHANNEL_OBJECT;
    this->peer = peer;
}

ObjectPacket::~ObjectPacket()
{

}

void ObjectPacket::setObjectList(BaseObjectList *objectList)
{
    this->objectList = objectList;
    guid = objectList->guid;
}

void ObjectPacket::Packet(RakNet::BitStream *bs, bool send)
{
    if (!PacketHeader(bs, send))
        return;

    BaseObject baseObject;
    for (unsigned int i = 0; i < objectList->baseObjectCount; i++)
    {
        if (send)
            baseObject = objectList->baseObjects.at(i);

        Object(baseObject, send);

        if (!send)
            objectList->baseObjects.push_back(baseObject);
    }
}

bool ObjectPacket::PacketHeader(RakNet::BitStream *bs, bool send)
{
    BasePacket::Packet(bs, send);

    if (send)
        objectList->baseObjectCount = (unsigned int)(objectList->baseObjects.size());
    else
        objectList->baseObjects.clear();

    RW(objectList->baseObjectCount, send);

    if (objectList->baseObjectCount > maxObjects)
    {
        objectList->isValid = false;
        return false;
    }

    if (hasCellData)
    {
        RW(objectList->cell.mData, send, 1);
        RW(objectList->cell.mName, send, 1);
    }

    return true;
}

void ObjectPacket::Object(BaseObject &baseObject, bool send)
{
    RW(baseObject.refId, send);
    RW(baseObject.refNumIndex, send);
    RW(baseObject.mpNum, send);
}
