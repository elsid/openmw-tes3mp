#ifndef OPENMW_PROCESSORPLAYERQUICKKEYS_HPP
#define OPENMW_PROCESSORPLAYERQUICKKEYS_HPP


#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerQuickKeys : public PlayerProcessor
    {
    public:
        ProcessorPlayerQuickKeys()
        {
            BPP_INIT(ID_PLAYER_QUICKKEYS)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            if (!isLocal()) return;

            LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Received ID_PLAYER_QUICKKEYS about LocalPlayer from server");

            if (!isRequest())
            {
                LocalPlayer &localPlayer = static_cast<LocalPlayer&>(*player);
                localPlayer.setQuickKeys();
            }
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERQUICKKEYS_HPP
