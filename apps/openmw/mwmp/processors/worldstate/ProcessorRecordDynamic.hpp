#ifndef OPENMW_PROCESSORRECORDDYNAMIC_HPP
#define OPENMW_PROCESSORRECORDDYNAMIC_HPP

#include "../WorldstateProcessor.hpp"

namespace mwmp
{
    class ProcessorRecordDynamic : public WorldstateProcessor
    {
    public:
        ProcessorRecordDynamic()
        {
            BPP_INIT(ID_RECORD_DYNAMIC)
        }

        virtual void Do(WorldstatePacket &packet, BaseWorldstate &worldstate)
        {
            // Placeholder
        }
    };
}

#endif //OPENMW_PROCESSORRECORDDYNAMIC_HPP
