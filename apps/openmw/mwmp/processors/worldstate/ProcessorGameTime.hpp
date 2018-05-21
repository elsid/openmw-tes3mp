#ifndef OPENMW_PROCESSORGAMETIME_HPP
#define OPENMW_PROCESSORGAMETIME_HPP


#include <apps/openmw/mwbase/world.hpp>
#include <apps/openmw/mwbase/environment.hpp>
#include "../WorldstateProcessor.hpp"

namespace mwmp
{
    class ProcessorGameTime : public WorldstateProcessor
    {
    public:
        ProcessorGameTime()
        {
            BPP_INIT(ID_GAME_TIME)
        }

        virtual void Do(WorldstatePacket &packet, BaseWorldstate &worldstate)
        {
            if (isLocal())
            {
                MWBase::World *world = MWBase::Environment::get().getWorld();
                if (worldstate.hour != -1)
                    world->setHour(worldstate.hour);
                else if (worldstate.day != -1)
                    world->setDay(worldstate.day);
                else if (worldstate.month != -1)
                    world->setMonth(worldstate.month);
            }
        }
    };
}



#endif //OPENMW_PROCESSORGAMETIME_HPP
