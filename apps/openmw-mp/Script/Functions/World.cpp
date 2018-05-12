#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Base/BaseObject.hpp>

#include <apps/openmw-mp/Networking.hpp>
#include <apps/openmw-mp/Player.hpp>
#include <apps/openmw-mp/Utils.hpp>
#include <apps/openmw-mp/Script/ScriptFunctions.hpp>

#include "World.hpp"

using namespace mwmp;

BaseObjectList *readObjectList;
BaseObjectList writeObjectList;

BaseObject tempObject;
const BaseObject emptyObject = {};

ContainerItem tempContainerItem;
const ContainerItem emptyContainerItem = {};

void WorldFunctions::ReadLastObjectList() noexcept
{
    readObjectList = mwmp::Networking::getPtr()->getLastObjectList();
}

void WorldFunctions::InitializeObjectList(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeObjectList.cell.blank();
    writeObjectList.baseObjects.clear();
    writeObjectList.guid = player->guid;
}

unsigned int WorldFunctions::GetObjectChangesSize() noexcept
{
    return readObjectList->baseObjectCount;
}

unsigned char WorldFunctions::GetObjectListAction() noexcept
{
    return readObjectList->action;
}

unsigned char WorldFunctions::GetObjectListContainerSubAction() noexcept
{
    return readObjectList->containerSubAction;
}

const char *WorldFunctions::GetObjectRefId(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).refId.c_str();
}

int WorldFunctions::GetObjectRefNumIndex(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).refNumIndex;
}

int WorldFunctions::GetObjectMpNum(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).mpNum;
}

int WorldFunctions::GetObjectCount(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).count;
}

int WorldFunctions::GetObjectCharge(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).charge;
}

double WorldFunctions::GetObjectEnchantmentCharge(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).enchantmentCharge;
}

int WorldFunctions::GetObjectGoldValue(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).goldValue;
}

double WorldFunctions::GetObjectScale(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).scale;
}

bool WorldFunctions::GetObjectState(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).objectState;
}

int WorldFunctions::GetObjectDoorState(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).doorState;
}

int WorldFunctions::GetObjectLockLevel(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).lockLevel;
}

double WorldFunctions::GetObjectPosX(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.pos[0];
}

double WorldFunctions::GetObjectPosY(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.pos[1];
}

double WorldFunctions::GetObjectPosZ(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.pos[2];
}

double WorldFunctions::GetObjectRotX(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.rot[0];
}

double WorldFunctions::GetObjectRotY(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.rot[1];
}

double WorldFunctions::GetObjectRotZ(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.rot[2];
}

unsigned int WorldFunctions::GetContainerChangesSize(unsigned int objectIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex).containerItemCount;
}

const char *WorldFunctions::GetContainerItemRefId(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).refId.c_str();
}

int WorldFunctions::GetContainerItemCount(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).count;
}

int WorldFunctions::GetContainerItemCharge(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).charge;
}

double WorldFunctions::GetContainerItemEnchantmentCharge(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).enchantmentCharge;
}

int WorldFunctions::GetContainerItemActionCount(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).actionCount;
}

void WorldFunctions::SetObjectListCell(const char* cellDescription) noexcept
{
    writeObjectList.cell = Utils::getCellFromDescription(cellDescription);
}

void WorldFunctions::SetObjectListAction(unsigned char action) noexcept
{
    writeObjectList.action = action;
}

void WorldFunctions::SetObjectListConsoleCommand(const char* consoleCommand) noexcept
{
    writeObjectList.consoleCommand = consoleCommand;
}

void WorldFunctions::SetObjectRefId(const char* refId) noexcept
{
    tempObject.refId = refId;
}

void WorldFunctions::SetObjectRefNumIndex(int refNumIndex) noexcept
{
    tempObject.refNumIndex = refNumIndex;
}

void WorldFunctions::SetObjectMpNum(int mpNum) noexcept
{
    tempObject.mpNum = mpNum;
}

void WorldFunctions::SetObjectCount(int count) noexcept
{
    tempObject.count = count;
}

void WorldFunctions::SetObjectCharge(int charge) noexcept
{
    tempObject.charge = charge;
}

void WorldFunctions::SetObjectEnchantmentCharge(double enchantmentCharge) noexcept
{
    tempObject.enchantmentCharge = enchantmentCharge;
}

void WorldFunctions::SetObjectGoldValue(int goldValue) noexcept
{
    tempObject.goldValue = goldValue;
}

void WorldFunctions::SetObjectScale(double scale) noexcept
{
    tempObject.scale = scale;
}

void WorldFunctions::SetObjectState(bool objectState) noexcept
{
    tempObject.objectState = objectState;
}

void WorldFunctions::SetObjectLockLevel(int lockLevel) noexcept
{
    tempObject.lockLevel = lockLevel;
}

void WorldFunctions::SetObjectDisarmState(bool disarmState) noexcept
{
    tempObject.isDisarmed = disarmState;
}

void WorldFunctions::SetObjectMasterState(bool masterState) noexcept
{
    tempObject.hasMaster = masterState;
}

void WorldFunctions::SetObjectPosition(double x, double y, double z) noexcept
{
    tempObject.position.pos[0] = x;
    tempObject.position.pos[1] = y;
    tempObject.position.pos[2] = z;
}

void WorldFunctions::SetObjectRotation(double x, double y, double z) noexcept
{
    tempObject.position.rot[0] = x;
    tempObject.position.rot[1] = y;
    tempObject.position.rot[2] = z;
}

void WorldFunctions::SetObjectDoorState(int doorState) noexcept
{
    tempObject.doorState = doorState;
}

void WorldFunctions::SetObjectDoorTeleportState(bool teleportState) noexcept
{
    tempObject.teleportState = teleportState;
}

void WorldFunctions::SetObjectDoorDestinationCell(const char* cellDescription) noexcept
{
    tempObject.destinationCell = Utils::getCellFromDescription(cellDescription);
}

void WorldFunctions::SetObjectDoorDestinationPosition(double x, double y, double z) noexcept
{
    tempObject.destinationPosition.pos[0] = x;
    tempObject.destinationPosition.pos[1] = y;
    tempObject.destinationPosition.pos[2] = z;
}

void WorldFunctions::SetObjectDoorDestinationRotation(double x, double z) noexcept
{
    tempObject.destinationPosition.rot[0] = x;
    tempObject.destinationPosition.rot[2] = z;
}

void WorldFunctions::SetPlayerAsObject(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    tempObject.guid = player->guid;
    tempObject.isPlayer = true;
}

void WorldFunctions::SetContainerItemRefId(const char* refId) noexcept
{
    tempContainerItem.refId = refId;
}

void WorldFunctions::SetContainerItemCount(int count) noexcept
{
    tempContainerItem.count = count;
}

void WorldFunctions::SetContainerItemCharge(int charge) noexcept
{
    tempContainerItem.charge = charge;
}

void WorldFunctions::SetContainerItemEnchantmentCharge(double enchantmentCharge) noexcept
{
    tempContainerItem.enchantmentCharge = enchantmentCharge;
}

void WorldFunctions::SetReceivedContainerItemActionCount(unsigned int objectIndex, unsigned int itemIndex, int actionCount) noexcept
{
    readObjectList->baseObjects.at(objectIndex).containerItems.at(itemIndex).actionCount = actionCount;
}

void WorldFunctions::AddObject() noexcept
{
    tempObject.droppedByPlayer = false;
    writeObjectList.baseObjects.push_back(tempObject);

    tempObject = emptyObject;
}

void WorldFunctions::AddContainerItem() noexcept
{
    tempObject.containerItems.push_back(tempContainerItem);

    tempContainerItem = emptyContainerItem;
}

void WorldFunctions::SendObjectPlace(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_PLACE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendObjectSpawn(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_SPAWN);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendObjectDelete(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_DELETE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendObjectLock(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_LOCK);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendObjectTrap(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_TRAP);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendObjectScale(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_SCALE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendObjectState(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_STATE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendDoorState(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_DOOR_STATE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendDoorDestination(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_DOOR_DESTINATION);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendContainer(bool broadcast, bool useLastReadObjectList) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_CONTAINER);
    
    if (useLastReadObjectList)
        packet->setObjectList(readObjectList);
    else
        packet->setObjectList(&writeObjectList);
    
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SendConsoleCommand(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_CONSOLE_COMMAND);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void WorldFunctions::SetHour(unsigned short pid, double hour) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->hour = hour;
    player->month = -1;
    player->day = -1;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->Send(false);
}

void WorldFunctions::SetMonth(unsigned short pid, int month) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->hour = -1;
    player->month = month;
    player->day = -1;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->Send(false);

}

void WorldFunctions::SetDay(unsigned short pid, int day) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->hour = -1;
    player->month = -1;
    player->day = day;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->Send(false);
}
