#ifndef OPENMW_PROCESSORPLAYERINTERACTION_HPP
#define OPENMW_PROCESSORPLAYERINTERACTION_HPP

#include "apps/openmw/mwmp/Main.hpp"
#include "../PlayerProcessor.hpp"
#include "apps/openmw/mwmp/MechanicsHelper.hpp"

namespace mwmp
{
    class ProcessorPlayerInteraction : public PlayerProcessor
    {
    public:
        ProcessorPlayerInteraction()
        {
            BPP_INIT(ID_PLAYER_INTERACTION)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            //if (player != 0)
            //    MechanicsHelper::processInteraction(player->interaction, static_cast<DedicatedPlayer*>(player)->getPtr());
        }
    };
}


#endif //OPENMW_PROCESSORPLAYERINTERACTION_HPP
