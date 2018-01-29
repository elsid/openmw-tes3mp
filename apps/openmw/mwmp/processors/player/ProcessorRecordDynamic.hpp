#ifndef OPENMW_PROCESSORRECORDDYNAMIC_HPP
#define OPENMW_PROCESSORRECORDDYNAMIC_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorRecordDynamic : public PlayerProcessor
    {
    public:
        ProcessorRecordDynamic()
        {
            BPP_INIT(ID_RECORD_DYNAMIC)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            // Placeholder
        }
    };
}

#endif //OPENMW_PROCESSORRECORDDYNAMIC_HPP
