//
// Created by koncord on 03.04.17.
//

#include "WorldProcessor.hpp"
#include "Networking.hpp"

using namespace mwmp;

template<class T>
typename BasePacketProcessor<T>::processors_t BasePacketProcessor<T>::processors;

void WorldProcessor::Do(ObjectPacket &packet, Player &player, BaseObjectList &objectList)
{
    packet.Send(true);
}

bool WorldProcessor::Process(RakNet::Packet &packet, BaseObjectList &objectList) noexcept
{
    // Clear our BaseObjectList before loading new data in it
    objectList.cell.blank();
    objectList.baseObjects.clear();
    objectList.guid = packet.guid;

    for (auto &processor : processors)
    {
        if (processor.first == packet.data[0])
        {
            Player *player = Players::getPlayer(packet.guid);
            ObjectPacket *myPacket = Networking::get().getObjectPacketController()->GetPacket(packet.data[0]);

            myPacket->setObjectList(&objectList);
            objectList.isValid = true;

            if (!processor.second->avoidReading)
                myPacket->Read();

            if (objectList.isValid)
                processor.second->Do(*myPacket, *player, objectList);
            else
                LOG_MESSAGE_SIMPLE(Log::LOG_ERROR, "Received %s that failed integrity check and was ignored!", processor.second->strPacketID.c_str());
            
            return true;
        }
    }
    return false;
}
