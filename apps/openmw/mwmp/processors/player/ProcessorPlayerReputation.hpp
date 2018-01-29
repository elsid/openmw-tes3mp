#ifndef OPENMW_PROCESSORPLAYERREPUTATION_HPP
#define OPENMW_PROCESSORPLAYERREPUTATION_HPP


#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerReputation : public PlayerProcessor
    {
    public:
        ProcessorPlayerReputation()
        {
            BPP_INIT(ID_PLAYER_REPUTATION)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            if (isLocal())
            {
                //if (isRequest())
                //    static_cast<LocalPlayer *>(player)->updateReputation(true);
                //else
                //    static_cast<LocalPlayer *>(player)->setReputation();
            }
            else if (player != 0)
            {
                MWWorld::Ptr ptrPlayer =  static_cast<DedicatedPlayer *>(player)->getPtr();
                MWMechanics::NpcStats *ptrNpcStats = &ptrPlayer.getClass().getNpcStats(ptrPlayer);

                ptrNpcStats->setReputation(player->npcStats.mReputation);
            }
        }
    };
}


#endif //OPENMW_PROCESSORPLAYERREPUTATION_HPP
