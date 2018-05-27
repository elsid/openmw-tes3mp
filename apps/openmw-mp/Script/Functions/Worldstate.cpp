#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Base/BaseWorldstate.hpp>

#include <apps/openmw-mp/Networking.hpp>
#include <apps/openmw-mp/Player.hpp>
#include <apps/openmw-mp/Script/ScriptFunctions.hpp>

#include "Worldstate.hpp"

using namespace std;
using namespace mwmp;

BaseWorldstate writeWorldstate;

void WorldstateFunctions::SetHour(double hour) noexcept
{
    writeWorldstate.hour = hour;
}

void WorldstateFunctions::SetDay(int day) noexcept
{
    writeWorldstate.day = day;
}

void WorldstateFunctions::SetMonth(int month) noexcept
{
    writeWorldstate.month = month;
}

void WorldstateFunctions::SetYear(int year) noexcept
{
    writeWorldstate.year = year;
}

void WorldstateFunctions::SetDaysPassed(int daysPassed) noexcept
{
    writeWorldstate.daysPassed = daysPassed;
}

void WorldstateFunctions::SetTimeScale(double timeScale) noexcept
{
    writeWorldstate.timeScale = timeScale;
}

void WorldstateFunctions::SetPlayerCollisionState(bool state) noexcept
{
    writeWorldstate.hasPlayerCollision = state;
}

void WorldstateFunctions::SetActorCollisionState(bool state) noexcept
{
    writeWorldstate.hasActorCollision = state;
}

void WorldstateFunctions::SetPlacedObjectCollisionState(bool state) noexcept
{
    writeWorldstate.hasPlacedObjectCollision = state;
}

void WorldstateFunctions::UseActorCollisionForPlacedObjects(bool useActorCollision) noexcept
{
    writeWorldstate.useActorCollisionForPlacedObjects = useActorCollision;
}

void WorldstateFunctions::SendWorldTime(unsigned short pid, bool toOthers) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeWorldstate.guid = player->guid;

    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_WORLD_TIME)->setWorldstate(&writeWorldstate);
    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_WORLD_TIME)->Send(false);

    if (toOthers)
        mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_WORLD_TIME)->Send(true);
}

void WorldstateFunctions::SendWorldCollisionOverride(unsigned short pid, bool toOthers) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeWorldstate.guid = player->guid;

    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_WORLD_COLLISION_OVERRIDE)->setWorldstate(&writeWorldstate);
    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_WORLD_COLLISION_OVERRIDE)->Send(false);

    if (toOthers)
        mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_WORLD_COLLISION_OVERRIDE)->Send(true);
}
