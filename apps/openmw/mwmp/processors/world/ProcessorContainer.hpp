#ifndef OPENMW_PROCESSORCONTAINER_HPP
#define OPENMW_PROCESSORCONTAINER_HPP

#include "BaseObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorContainer : public BaseObjectProcessor
    {
    public:
        ProcessorContainer()
        {
            BPP_INIT(ID_CONTAINER)
        }

        virtual void Do(WorldPacket &packet, WorldEvent &event)
        {
            BaseObjectProcessor::Do(packet, event);

            LOG_APPEND(Log::LOG_VERBOSE, "- action: %i, containerSubAction: %i", event.action, event.containerSubAction);

            // If we've received a request for information, comply with it
            if (event.action == mwmp::BaseEvent::REQUEST)
            {
                if (event.worldObjectCount == 0)
                {
                    LOG_APPEND(Log::LOG_VERBOSE, "- Request had no objects attached, so we are sending all containers in the cell %s",
                        event.cell.getDescription().c_str());
                    event.reset();
                    event.cell = *ptrCellStore->getCell();
                    event.action = event.action == mwmp::BaseEvent::SET;
                    event.addAllContainers(ptrCellStore);
                    event.sendContainer();
                }
                else
                {
                    LOG_APPEND(Log::LOG_VERBOSE, "- Request was for %i %s", event.worldObjectCount, event.worldObjectCount == 1 ? "object" : "objects");
                    std::vector<WorldObject> requestObjects = event.worldObjects;
                    event.reset();
                    event.cell = *ptrCellStore->getCell();
                    event.action = event.action == mwmp::BaseEvent::SET;
                    event.addRequestedContainers(ptrCellStore, requestObjects);

                    if (event.worldObjects.size() > 0)
                        event.sendContainer();
                }
            }
                // Otherwise, edit containers based on the information received
            else
            {
                LOG_APPEND(Log::LOG_VERBOSE, "- Editing container contents to match those of packet", event.worldObjectCount);
                event.editContainers(ptrCellStore);
            }
        }

    };
}

#endif //OPENMW_PROCESSORCONTAINER_HPP
