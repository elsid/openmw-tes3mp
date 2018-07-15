#ifndef OPENMW_PROCESSORGAMEWEATHER_HPP
#define OPENMW_PROCESSORGAMEWEATHER_HPP

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

        virtual void Do(WorldstatePacket &packet, Worldstate &worldstate)
        {
            // Placeholder to be filled in later
        }
    };
}

#endif //OPENMW_PROCESSORGAMEWEATHER_HPP
