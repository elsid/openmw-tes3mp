#ifndef OPENMW_PROCESSDOORDESTINATION_HPP
#define OPENMW_PROCESSDOORDESTINATION_HPP

#include "BaseObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorDoorDestination : public BaseObjectProcessor
    {
    public:
        ProcessorDoorDestination()
        {
            BPP_INIT(ID_DOOR_DESTINATION)
        }

        virtual void Do(WorldPacket &packet, WorldEvent &event)
        {
            BaseObjectProcessor::Do(packet, event);

            event.setDoorDestinations(ptrCellStore);
        }
    };
}

#endif //OPENMW_PROCESSDOORDESTINATION_HPP
