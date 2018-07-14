#ifndef OPENMW_PROCESSORCELLREPLACE_HPP
#define OPENMW_PROCESSORCELLREPLACE_HPP

#include "../WorldstateProcessor.hpp"

namespace mwmp
{
    class ProcessorCellReplace : public WorldstateProcessor
    {
    public:
        ProcessorCellReplace()
        {
            BPP_INIT(ID_CELL_REPLACE)
        }

        virtual void Do(WorldstatePacket &packet, Worldstate &worldstate)
        {
            // Placeholder
        }
    };
}

#endif //OPENMW_PROCESSORCELLREPLACE_HPP
