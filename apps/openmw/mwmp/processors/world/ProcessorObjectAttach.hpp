#ifndef OPENMW_PROCESSOROBJECTATTACH_HPP
#define OPENMW_PROCESSOROBJECTATTACH_HPP

#include "BaseObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorObjectAttach : public BaseObjectProcessor
    {
    public:
        ProcessorObjectAttach()
        {
            BPP_INIT(ID_OBJECT_ATTACH)
        }

        virtual void Do(ObjectPacket &packet, WorldEvent &event)
        {
            BaseObjectProcessor::Do(packet, event);

            //event.attachObjects(ptrCellStore);
        }

    };
}

#endif //OPENMW_PROCESSOROBJECTATTACH_HPP
