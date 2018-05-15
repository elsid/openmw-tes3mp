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

        virtual void Do(ObjectPacket &packet, ObjectList &objectList)
        {
            BaseObjectProcessor::Do(packet, objectList);

            objectList.setDoorDestinations(ptrCellStore);
        }
    };
}

#endif //OPENMW_PROCESSDOORDESTINATION_HPP
