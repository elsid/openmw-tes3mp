#ifndef OPENMW_PROCESSOROBJECTRESET_HPP
#define OPENMW_PROCESSOROBJECTRESET_HPP

#include "BaseObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorObjectReset : public BaseObjectProcessor
    {
    public:
        ProcessorObjectReset()
        {
            BPP_INIT(ID_OBJECT_RESET)
        }

        virtual void Do(WorldPacket &packet, WorldEvent &event)
        {
            BaseObjectProcessor::Do(packet, event);

            //event.resetObjects(ptrCellStore);
        }

    };
}

#endif //OPENMW_PROCESSOROBJECTRESET_HPP
