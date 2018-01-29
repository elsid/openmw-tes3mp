#ifndef OPENMW_PROCESSORPLAYERINTERACTION_HPP
#define OPENMW_PROCESSORPLAYERINTERACTION_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerInteraction : public PlayerProcessor
    {
    public:
        ProcessorPlayerInteraction()
        {
            BPP_INIT(ID_PLAYER_INTERACTION)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Script::Call<Script::CallbackIdentity("OnPlayerInteraction")>(player.getId());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERINTERACTION_HPP
