#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Base/BaseObject.hpp>

#include <apps/openmw-mp/Networking.hpp>
#include <apps/openmw-mp/Player.hpp>
#include <apps/openmw-mp/Utils.hpp>
#include <apps/openmw-mp/Script/ScriptFunctions.hpp>

#include "Objects.hpp"

using namespace mwmp;

BaseObjectList *readObjectList;
BaseObjectList writeObjectList;

BaseObject tempObject;
const BaseObject emptyObject = {};

ContainerItem tempContainerItem;
const ContainerItem emptyContainerItem = {};

void ObjectFunctions::ReadLastObjectList() noexcept
{
    readObjectList = mwmp::Networking::getPtr()->getLastObjectList();
}

void ObjectFunctions::InitializeObjectList(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    writeObjectList.cell.blank();
    writeObjectList.baseObjects.clear();
    writeObjectList.guid = player->guid;
}

unsigned int ObjectFunctions::GetObjectChangesSize() noexcept
{
    return readObjectList->baseObjectCount;
}

unsigned char ObjectFunctions::GetObjectListAction() noexcept
{
    return readObjectList->action;
}

unsigned char ObjectFunctions::GetObjectListContainerSubAction() noexcept
{
    return readObjectList->containerSubAction;
}

const char *ObjectFunctions::GetObjectRefId(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).refId.c_str();
}

int ObjectFunctions::GetObjectRefNumIndex(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).refNumIndex;
}

int ObjectFunctions::GetObjectMpNum(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).mpNum;
}

int ObjectFunctions::GetObjectCount(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).count;
}

int ObjectFunctions::GetObjectCharge(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).charge;
}

double ObjectFunctions::GetObjectEnchantmentCharge(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).enchantmentCharge;
}

int ObjectFunctions::GetObjectGoldValue(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).goldValue;
}

double ObjectFunctions::GetObjectScale(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).scale;
}

bool ObjectFunctions::GetObjectState(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).objectState;
}

int ObjectFunctions::GetObjectDoorState(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).doorState;
}

int ObjectFunctions::GetObjectLockLevel(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).lockLevel;
}

double ObjectFunctions::GetObjectPosX(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.pos[0];
}

double ObjectFunctions::GetObjectPosY(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.pos[1];
}

double ObjectFunctions::GetObjectPosZ(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.pos[2];
}

double ObjectFunctions::GetObjectRotX(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.rot[0];
}

double ObjectFunctions::GetObjectRotY(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.rot[1];
}

double ObjectFunctions::GetObjectRotZ(unsigned int i) noexcept
{
    return readObjectList->baseObjects.at(i).position.rot[2];
}

unsigned int ObjectFunctions::GetContainerChangesSize(unsigned int objectIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex).containerItemCount;
}

const char *ObjectFunctions::GetContainerItemRefId(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).refId.c_str();
}

int ObjectFunctions::GetContainerItemCount(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).count;
}

int ObjectFunctions::GetContainerItemCharge(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).charge;
}

double ObjectFunctions::GetContainerItemEnchantmentCharge(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).enchantmentCharge;
}

int ObjectFunctions::GetContainerItemActionCount(unsigned int objectIndex, unsigned int itemIndex) noexcept
{
    return readObjectList->baseObjects.at(objectIndex)
        .containerItems.at(itemIndex).actionCount;
}

void ObjectFunctions::SetObjectListCell(const char* cellDescription) noexcept
{
    writeObjectList.cell = Utils::getCellFromDescription(cellDescription);
}

void ObjectFunctions::SetObjectListAction(unsigned char action) noexcept
{
    writeObjectList.action = action;
}

void ObjectFunctions::SetObjectListConsoleCommand(const char* consoleCommand) noexcept
{
    writeObjectList.consoleCommand = consoleCommand;
}

void ObjectFunctions::SetObjectRefId(const char* refId) noexcept
{
    tempObject.refId = refId;
}

void ObjectFunctions::SetObjectRefNumIndex(int refNumIndex) noexcept
{
    tempObject.refNumIndex = refNumIndex;
}

void ObjectFunctions::SetObjectMpNum(int mpNum) noexcept
{
    tempObject.mpNum = mpNum;
}

void ObjectFunctions::SetObjectCount(int count) noexcept
{
    tempObject.count = count;
}

void ObjectFunctions::SetObjectCharge(int charge) noexcept
{
    tempObject.charge = charge;
}

void ObjectFunctions::SetObjectEnchantmentCharge(double enchantmentCharge) noexcept
{
    tempObject.enchantmentCharge = enchantmentCharge;
}

void ObjectFunctions::SetObjectGoldValue(int goldValue) noexcept
{
    tempObject.goldValue = goldValue;
}

void ObjectFunctions::SetObjectScale(double scale) noexcept
{
    tempObject.scale = scale;
}

void ObjectFunctions::SetObjectState(bool objectState) noexcept
{
    tempObject.objectState = objectState;
}

void ObjectFunctions::SetObjectLockLevel(int lockLevel) noexcept
{
    tempObject.lockLevel = lockLevel;
}

void ObjectFunctions::SetObjectDisarmState(bool disarmState) noexcept
{
    tempObject.isDisarmed = disarmState;
}

void ObjectFunctions::SetObjectMasterState(bool masterState) noexcept
{
    tempObject.hasMaster = masterState;
}

void ObjectFunctions::SetObjectPosition(double x, double y, double z) noexcept
{
    tempObject.position.pos[0] = x;
    tempObject.position.pos[1] = y;
    tempObject.position.pos[2] = z;
}

void ObjectFunctions::SetObjectRotation(double x, double y, double z) noexcept
{
    tempObject.position.rot[0] = x;
    tempObject.position.rot[1] = y;
    tempObject.position.rot[2] = z;
}

void ObjectFunctions::SetObjectDoorState(int doorState) noexcept
{
    tempObject.doorState = doorState;
}

void ObjectFunctions::SetObjectDoorTeleportState(bool teleportState) noexcept
{
    tempObject.teleportState = teleportState;
}

void ObjectFunctions::SetObjectDoorDestinationCell(const char* cellDescription) noexcept
{
    tempObject.destinationCell = Utils::getCellFromDescription(cellDescription);
}

void ObjectFunctions::SetObjectDoorDestinationPosition(double x, double y, double z) noexcept
{
    tempObject.destinationPosition.pos[0] = x;
    tempObject.destinationPosition.pos[1] = y;
    tempObject.destinationPosition.pos[2] = z;
}

void ObjectFunctions::SetObjectDoorDestinationRotation(double x, double z) noexcept
{
    tempObject.destinationPosition.rot[0] = x;
    tempObject.destinationPosition.rot[2] = z;
}

void ObjectFunctions::SetPlayerAsObject(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    tempObject.guid = player->guid;
    tempObject.isPlayer = true;
}

void ObjectFunctions::SetContainerItemRefId(const char* refId) noexcept
{
    tempContainerItem.refId = refId;
}

void ObjectFunctions::SetContainerItemCount(int count) noexcept
{
    tempContainerItem.count = count;
}

void ObjectFunctions::SetContainerItemCharge(int charge) noexcept
{
    tempContainerItem.charge = charge;
}

void ObjectFunctions::SetContainerItemEnchantmentCharge(double enchantmentCharge) noexcept
{
    tempContainerItem.enchantmentCharge = enchantmentCharge;
}

void ObjectFunctions::SetReceivedContainerItemActionCount(unsigned int objectIndex, unsigned int itemIndex, int actionCount) noexcept
{
    readObjectList->baseObjects.at(objectIndex).containerItems.at(itemIndex).actionCount = actionCount;
}

void ObjectFunctions::AddObject() noexcept
{
    tempObject.droppedByPlayer = false;
    writeObjectList.baseObjects.push_back(tempObject);

    tempObject = emptyObject;
}

void ObjectFunctions::AddContainerItem() noexcept
{
    tempObject.containerItems.push_back(tempContainerItem);

    tempContainerItem = emptyContainerItem;
}

void ObjectFunctions::SendObjectPlace(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_PLACE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SendObjectSpawn(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_SPAWN);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SendObjectDelete(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_DELETE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SendObjectLock(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_LOCK);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SendObjectTrap(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_TRAP);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SendObjectScale(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_SCALE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SendObjectState(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_OBJECT_STATE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SendDoorState(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_DOOR_STATE);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SendDoorDestination(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_DOOR_DESTINATION);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SendContainer(bool broadcast, bool useLastReadObjectList) noexcept
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

void ObjectFunctions::SendConsoleCommand(bool broadcast) noexcept
{
    mwmp::ObjectPacket *packet = mwmp::Networking::get().getObjectPacketController()->GetPacket(ID_CONSOLE_COMMAND);
    packet->setObjectList(&writeObjectList);
    packet->Send(false);

    if (broadcast)
        packet->Send(true);
}

void ObjectFunctions::SetHour(unsigned short pid, double hour) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->hour = hour;
    player->month = -1;
    player->day = -1;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->Send(false);
}

void ObjectFunctions::SetMonth(unsigned short pid, int month) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->hour = -1;
    player->month = month;
    player->day = -1;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->Send(false);

}

void ObjectFunctions::SetDay(unsigned short pid, int day) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->hour = -1;
    player->month = -1;
    player->day = day;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_TIME)->Send(false);
}
