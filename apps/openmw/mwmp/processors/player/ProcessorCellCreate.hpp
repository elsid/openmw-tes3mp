#ifndef OPENMW_PROCESSORCELLCREATE_HPP
#define OPENMW_PROCESSORCELLCREATE_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorCellCreate : public PlayerProcessor
    {
    public:
        ProcessorCellCreate()
        {
            BPP_INIT(ID_CELL_CREATE)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            // Placeholder
        }
    };
}

#endif //OPENMW_PROCESSORCELLCREATE_HPP
