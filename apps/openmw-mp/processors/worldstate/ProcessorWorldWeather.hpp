#ifndef OPENMW_PROCESSORWORLDWEATHER_HPP
#define OPENMW_PROCESSORWORLDWEATHER_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorWorldWeather : public WorldstateProcessor
    {
    public:
        ProcessorWorldWeather()
        {
            BPP_INIT(ID_WORLD_WEATHER)
        }

        void Do(WorldstatePacket &packet, Player &player, BaseWorldstate &worldstate) override
        {
            // Placeholder to be filled in later
        }
    };
}

#endif //OPENMW_PROCESSORWORLDWEATHER_HPP
