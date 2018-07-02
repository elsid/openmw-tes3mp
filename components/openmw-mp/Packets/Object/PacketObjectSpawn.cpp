#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectSpawn.hpp"

using namespace mwmp;

PacketObjectSpawn::PacketObjectSpawn(RakNet::RakPeerInterface *peer) : ObjectPacket(peer)
{
    packetID = ID_OBJECT_SPAWN;
    hasCellData = true;
}

void PacketObjectSpawn::Object(BaseObject &baseObject, bool send)
{
    ObjectPacket::Object(baseObject, send);
    RW(baseObject.position, send);
    RW(baseObject.summonDuration, send);

    RW(baseObject.isSummon, send);

    if (baseObject.isSummon)
    {
        RW(baseObject.master.isPlayer, send);

        if (baseObject.master.isPlayer)
        {
            RW(baseObject.master.guid, send);
        }
        else
        {
            RW(baseObject.master.refId, send, true);
            RW(baseObject.master.refNumIndex, send);
            RW(baseObject.master.mpNum, send);
        }
    }
}
