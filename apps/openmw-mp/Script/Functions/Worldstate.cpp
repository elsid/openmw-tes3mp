#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Base/BaseWorldstate.hpp>

#include <apps/openmw-mp/Networking.hpp>
#include <apps/openmw-mp/Player.hpp>
#include <apps/openmw-mp/Script/ScriptFunctions.hpp>

#include "Worldstate.hpp"

using namespace std;
using namespace mwmp;

BaseWorldstate writeWorldstate;

void WorldstateFunctions::SetHour(unsigned short pid, double hour) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeWorldstate.guid = player->guid;

    writeWorldstate.hour = hour;
    writeWorldstate.month = -1;
    writeWorldstate.day = -1;

    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_GAME_TIME)->setWorldstate(&writeWorldstate);
    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_GAME_TIME)->Send(false);
}

void WorldstateFunctions::SetMonth(unsigned short pid, int month) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeWorldstate.guid = player->guid;

    writeWorldstate.hour = -1;
    writeWorldstate.month = month;
    writeWorldstate.day = -1;

    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_GAME_TIME)->setWorldstate(&writeWorldstate);
    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_GAME_TIME)->Send(false);

}

void WorldstateFunctions::SetDay(unsigned short pid, int day) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeWorldstate.guid = player->guid;

    writeWorldstate.hour = -1;
    writeWorldstate.month = -1;
    writeWorldstate.day = day;

    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_GAME_TIME)->setWorldstate(&writeWorldstate);
    mwmp::Networking::get().getWorldstatePacketController()->GetPacket(ID_GAME_TIME)->Send(false);
}
