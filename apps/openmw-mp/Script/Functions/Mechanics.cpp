#include "Mechanics.hpp"

#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Log.hpp>

#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>

#include <iostream>
using namespace std;

static std::string tempCellDescription;

unsigned char MechanicsFunctions::GetMiscellaneousChangeType(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->miscellaneousChangeType;
}

const char *MechanicsFunctions::GetMarkCell(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    tempCellDescription = player->cell.getDescription().c_str();
    return tempCellDescription.c_str();
}

double MechanicsFunctions::GetMarkPosX(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0.0f);

    return player->markPosition.pos[0];
}

double MechanicsFunctions::GetMarkPosY(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0.0f);

    return player->markPosition.pos[1];
}

double MechanicsFunctions::GetMarkPosZ(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0.0f);

    return player->markPosition.pos[2];
}

double MechanicsFunctions::GetMarkRotX(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0.0f);

    return player->markPosition.rot[0];
}

double MechanicsFunctions::GetMarkRotZ(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0.0f);

    return player->markPosition.rot[2];
}

bool MechanicsFunctions::IsWerewolf(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->isWerewolf;
}

void MechanicsFunctions::SetMarkCell(unsigned short pid, const char *cellDescription) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->markCell = Utils::getCellFromDescription(cellDescription);
}

void MechanicsFunctions::SetMarkPos(unsigned short pid, double x, double y, double z) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->markPosition.pos[0] = x;
    player->markPosition.pos[1] = y;
    player->markPosition.pos[2] = z;
}

void MechanicsFunctions::SetMarkRot(unsigned short pid, double x, double z) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->markPosition.rot[0] = x;
    player->markPosition.rot[2] = z;
}

void MechanicsFunctions::SetWerewolfState(unsigned short pid, bool isWerewolf)
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->isWerewolf = isWerewolf;
}

void MechanicsFunctions::SendMarkLocation(unsigned short pid)
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->miscellaneousChangeType = mwmp::MISCELLANEOUS_CHANGE_TYPE::MARK_LOCATION;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_MISCELLANEOUS)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_MISCELLANEOUS)->Send(false);
}

void MechanicsFunctions::SendShapeshift(unsigned short pid)
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_SHAPESHIFT)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_SHAPESHIFT)->Send(false);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_SHAPESHIFT)->Send(true);
}

void MechanicsFunctions::Jail(unsigned short pid, int jailDays, bool ignoreJailTeleportation, bool ignoreJailSkillIncreases,
                              const char* jailProgressText, const char* jailEndText) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->jailDays = jailDays;
    player->ignoreJailTeleportation = ignoreJailTeleportation;
    player->ignoreJailSkillIncreases = ignoreJailSkillIncreases;
    player->jailProgressText = jailProgressText;
    player->jailEndText = jailEndText;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_JAIL)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_JAIL)->Send(false);
}

void MechanicsFunctions::Resurrect(unsigned short pid, unsigned int type) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->resurrectType = type;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_RESURRECT)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_RESURRECT)->Send(false);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_RESURRECT)->Send(true);
}
