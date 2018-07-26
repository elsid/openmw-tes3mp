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

        virtual void Do(WorldstatePacket &packet, Worldstate &worldstate)
        {
            MWBase::World *world = MWBase::Environment::get().getWorld();

            if (worldstate.time.hour != -1)
                world->setHour(worldstate.time.hour);
            
            if (worldstate.time.day != -1)
                world->setDay(worldstate.time.day);
            
            if (worldstate.time.month != -1)
                world->setMonth(worldstate.time.month);

            if (worldstate.time.year != -1)
                world->setYear(worldstate.time.year);

            if (worldstate.time.daysPassed != -1)
                world->setDaysPassed(worldstate.time.daysPassed);

            if (worldstate.time.timeScale != -1)
                world->setTimeScale(worldstate.time.timeScale);
        }
    };
}



#endif //OPENMW_PROCESSORWORLDTIME_HPP
