#ifndef OPENMW_PROCESSORWORLDREGIONAUTHORITY_HPP
#define OPENMW_PROCESSORWORLDREGIONAUTHORITY_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorWorldRegionAuthority : public WorldstateProcessor
    {
    public:
        ProcessorWorldRegionAuthority()
        {
            BPP_INIT(ID_WORLD_REGION_AUTHORITY)
        }

        virtual void Do(WorldstatePacket &packet, Worldstate &worldstate)
        {
            if (isLocal())
            {
                LOG_APPEND(Log::LOG_INFO, "- The new region authority for %s is me");
                
            }
            else
            {

            }
        }
    };
}

#endif //OPENMW_PROCESSORWORLDREGIONAUTHORITY_HPP
