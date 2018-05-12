#ifndef OPENMW_WORLDPACKET_HPP
#define OPENMW_WORLDPACKET_HPP

#include <string>
#include <RakNetTypes.h>
#include <BitStream.h>
#include <PacketPriority.h>
#include <components/openmw-mp/Base/BaseEvent.hpp>

#include <components/openmw-mp/Packets/BasePacket.hpp>


namespace mwmp
{
    class ObjectPacket : public BasePacket
    {
    public:
        ObjectPacket(RakNet::RakPeerInterface *peer);

        ~ObjectPacket();

        void setEvent(BaseEvent *event);

        virtual void Packet(RakNet::BitStream *bs, bool send);

    protected:
        virtual void Object(WorldObject &worldObject, bool send);
        bool PacketHeader(RakNet::BitStream *bs, bool send);
        BaseEvent *event;
        static const int maxObjects = 3000;
        bool hasCellData;
    };
}

#endif //OPENMW_WORLDPACKET_HPP
