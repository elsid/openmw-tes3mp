#ifndef OPENMW_PROCESSORPLAYERMISCELLANEOUS_HPP
#define OPENMW_PROCESSORPLAYERMISCELLANEOUS_HPP


#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerMiscellaneous : public PlayerProcessor
    {
    public:
        ProcessorPlayerMiscellaneous()
        {
            BPP_INIT(ID_PLAYER_MISCELLANEOUS)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            if (!isLocal()) return;

            LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Received ID_PLAYER_MISCELLANEOUS about LocalPlayer from server");

            if (!isRequest())
            {
                LocalPlayer &localPlayer = static_cast<LocalPlayer&>(*player);
                //localPlayer.setMiscellaneous();
            }
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERMISCELLANEOUS_HPP
