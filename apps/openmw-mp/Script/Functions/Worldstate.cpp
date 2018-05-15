#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Networking.hpp>
#include <apps/openmw-mp/Player.hpp>
#include <apps/openmw-mp/Script/ScriptFunctions.hpp>

#include "Worldstate.hpp"

#include <iostream>
using namespace std;

void WorldstateFunctions::SetHour(unsigned short pid, double hour) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->hour = hour;
    player->month = -1;
    player->day = -1;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->Send(false);
}

void WorldstateFunctions::SetMonth(unsigned short pid, int month) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->hour = -1;
    player->month = month;
    player->day = -1;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->Send(false);

}

void WorldstateFunctions::SetDay(unsigned short pid, int day) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->hour = -1;
    player->month = -1;
    player->day = day;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->Send(false);
}
