#ifndef OPENMW_PROCESSORCELLCREATE_HPP
#define OPENMW_PROCESSORCELLCREATE_HPP

#include "../WorldstateProcessor.hpp"

namespace mwmp
{
    class ProcessorCellCreate : public WorldstateProcessor
    {
    public:
        ProcessorCellCreate()
        {
            BPP_INIT(ID_CELL_CREATE)
        }

        virtual void Do(WorldstatePacket &packet, Worldstate &worldstate)
        {
            // Placeholder
        }
    };
}

#endif //OPENMW_PROCESSORCELLCREATE_HPP
