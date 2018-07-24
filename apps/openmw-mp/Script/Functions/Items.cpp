#include "Items.hpp"

#include <components/misc/stringops.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>
#include <apps/openmw/mwworld/inventorystore.hpp>

using namespace mwmp;

void ItemFunctions::InitializeInventoryChanges(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->inventoryChanges.items.clear();
    player->inventoryChanges.action = InventoryChanges::SET;
}

int ItemFunctions::GetEquipmentSize() noexcept
{
    return MWWorld::InventoryStore::Slots;
}

unsigned int ItemFunctions::GetInventoryChangesSize(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->inventoryChanges.count;
}

void ItemFunctions::EquipItem(unsigned short pid, unsigned short slot, const char *refId, unsigned int count, int charge, double enchantmentCharge) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->equipmentItems[slot].refId = refId;
    player->equipmentItems[slot].count = count;
    player->equipmentItems[slot].charge = charge;
    player->equipmentItems[slot].enchantmentCharge = enchantmentCharge;

    if (!Utils::vectorContains(player->equipmentIndexChanges, slot))
        player->equipmentIndexChanges.push_back(slot);
}

void ItemFunctions::UnequipItem(unsigned short pid, unsigned short slot) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    ItemFunctions::EquipItem(pid, slot, "", 0, -1, -1);
}

void ItemFunctions::AddItem(unsigned short pid, const char* refId, unsigned int count, int charge, double enchantmentCharge) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    Item item;
    item.refId = refId;
    item.count = count;
    item.charge = charge;
    item.enchantmentCharge = enchantmentCharge;

    player->inventoryChanges.items.push_back(item);
    player->inventoryChanges.action = InventoryChanges::ADD;
}

void ItemFunctions::RemoveItem(unsigned short pid, const char* refId, unsigned short count) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    Item item;
    item.refId = refId;
    item.count = count;

    player->inventoryChanges.items.push_back(item);
    player->inventoryChanges.action = InventoryChanges::REMOVE;
}

bool ItemFunctions::HasItemEquipped(unsigned short pid, const char* refId)
{
    Player *player;
    GET_PLAYER(pid, player, false);

    for (int slot = 0; slot < MWWorld::InventoryStore::Slots; slot++)
        if (Misc::StringUtils::ciEqual(player->equipmentItems[slot].refId, refId))
            return true;
    return false;
}

const char *ItemFunctions::GetEquipmentItemRefId(unsigned short pid, unsigned short slot) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->equipmentItems[slot].refId.c_str();
}

int ItemFunctions::GetEquipmentItemCount(unsigned short pid, unsigned short slot) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->equipmentItems[slot].count;
}

int ItemFunctions::GetEquipmentItemCharge(unsigned short pid, unsigned short slot) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->equipmentItems[slot].charge;
}

double ItemFunctions::GetEquipmentItemEnchantmentCharge(unsigned short pid, unsigned short slot) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->equipmentItems[slot].enchantmentCharge;
}

const char *ItemFunctions::GetInventoryItemRefId(unsigned short pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->inventoryChanges.count)
        return "invalid";

    return player->inventoryChanges.items.at(index).refId.c_str();
}

int ItemFunctions::GetInventoryItemCount(unsigned short pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->inventoryChanges.items.at(index).count;
}

int ItemFunctions::GetInventoryItemCharge(unsigned short pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->inventoryChanges.items.at(index).charge;
}

double ItemFunctions::GetInventoryItemEnchantmentCharge(unsigned short pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->inventoryChanges.items.at(index).enchantmentCharge;
}

void ItemFunctions::SendEquipment(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_EQUIPMENT);
    packet->setPlayer(player);

    packet->Send(false);
    packet->Send(true);

    player->equipmentIndexChanges.clear();
}

void ItemFunctions::SendInventoryChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_INVENTORY);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}
