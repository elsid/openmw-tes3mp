#ifndef OPENMW_PROCESSORPLAYERMAP_HPP
#define OPENMW_PROCESSORPLAYERMAP_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerMap : public PlayerProcessor
    {
    public:
        ProcessorPlayerMap()
        {
            BPP_INIT(ID_PLAYER_MAP)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Script::Call<Script::CallbackIdentity("OnPlayerMap")>(player.getId());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERMAP_HPP
