#ifndef OPENMW_PROCESSORWORLDKILLCOUNT_HPP
#define OPENMW_PROCESSORWORLDKILLCOUNT_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorWorldKillCount : public PlayerProcessor
    {
    public:
        ProcessorWorldKillCount()
        {
            BPP_INIT(ID_WORLD_KILL_COUNT)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            if (isRequest())
            {
                // Entire list of topics cannot currently be requested from players
            }
            else if (player != 0)
            {
                static_cast<LocalPlayer*>(player)->setKills();
            }
        }
    };
}

#endif //OPENMW_PROCESSORWORLDKILLCOUNT_HPP
