#ifndef OPENMW_PROCESSORPLAYERCAST_HPP
#define OPENMW_PROCESSORPLAYERCAST_HPP

#include "apps/openmw/mwmp/Main.hpp"
#include "../PlayerProcessor.hpp"
#include "apps/openmw/mwmp/MechanicsHelper.hpp"

namespace mwmp
{
    class ProcessorPlayerCast final: public PlayerProcessor
    {
    public:
        ProcessorPlayerCast()
        {
            BPP_INIT(ID_PLAYER_CAST)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            if (player != 0)
                MechanicsHelper::processCast(player->cast, static_cast<DedicatedPlayer*>(player)->getPtr());
        }
    };
}


#endif //OPENMW_PROCESSORPLAYERCAST_HPP
