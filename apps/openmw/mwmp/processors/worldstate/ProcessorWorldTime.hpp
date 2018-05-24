#ifndef OPENMW_PROCESSORWORLDTIME_HPP
#define OPENMW_PROCESSORWORLDTIME_HPP


#include <apps/openmw/mwbase/world.hpp>
#include <apps/openmw/mwbase/environment.hpp>
#include "../WorldstateProcessor.hpp"

namespace mwmp
{
    class ProcessorWorldTime : public WorldstateProcessor
    {
    public:
        ProcessorWorldTime()
        {
            BPP_INIT(ID_WORLD_TIME)
        }

        virtual void Do(WorldstatePacket &packet, BaseWorldstate &worldstate)
        {
            if (isLocal())
            {
                MWBase::World *world = MWBase::Environment::get().getWorld();
                if (worldstate.hour != -1)
                    world->setHour(worldstate.hour);
                
                if (worldstate.day != -1)
                    world->setDay(worldstate.day);
                
                if (worldstate.month != -1)
                    world->setMonth(worldstate.month);
                
                if (worldstate.timeScale != -1)
                    world->setTimeScale(worldstate.timeScale);
            }
        }
    };
}



#endif //OPENMW_PROCESSORWORLDTIME_HPP
