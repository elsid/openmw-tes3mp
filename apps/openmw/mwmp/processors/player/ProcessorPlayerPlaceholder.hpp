#ifndef OPENMW_PROCESSORPLACEHOLDER_HPP
#define OPENMW_PROCESSORPLACEHOLDER_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerPlaceholder final: public PlayerProcessor
    {
    public:
        ProcessorPlayerPlaceholder()
        {
            BPP_INIT(ID_PLACEHOLDER)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            if (isRequest())
            {
                // Entire list of topics cannot currently be requested from players
            }
            else if (player != 0)
            {
                // Placeholder
            }
        }
    };
}

#endif //OPENMW_PROCESSORPLACEHOLDER_HPP
