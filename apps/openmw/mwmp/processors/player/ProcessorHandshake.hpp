#ifndef OPENMW_PROCESSORHANDSHAKE_HPP
#define OPENMW_PROCESSORHANDSHAKE_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorHandshake final: public PlayerProcessor
    {
    public:
        ProcessorHandshake()
        {
            BPP_INIT(ID_HANDSHAKE)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            packet.setPlayer(getLocalPlayer()); // player is 0 because myGuid will be set after ProcessUserMyID
            packet.Send(serverAddr);
        }
    };
}

#endif //OPENMW_PROCESSORHANDSHAKE_HPP
