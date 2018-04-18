//
// Created by koncord on 30.08.16.
//

#ifndef OPENMW_ITEMAPI_HPP
#define OPENMW_ITEMAPI_HPP

#define ITEMAPI \
    {"InitializeInventoryChanges",            ItemFunctions::InitializeInventoryChanges},\
    \
    {"GetEquipmentSize",                      ItemFunctions::GetEquipmentSize},\
    {"GetInventoryChangesSize",               ItemFunctions::GetInventoryChangesSize},\
    \
    {"EquipItem",                             ItemFunctions::EquipItem},\
    {"UnequipItem",                           ItemFunctions::UnequipItem},\
    \
    {"AddItem",                               ItemFunctions::AddItem},\
    {"RemoveItem",                            ItemFunctions::RemoveItem},\
    \
    {"HasItemEquipped",                       ItemFunctions::HasItemEquipped},\
    \
    {"GetEquipmentItemRefId",                 ItemFunctions::GetEquipmentItemRefId},\
    {"GetEquipmentItemCount",                 ItemFunctions::GetEquipmentItemCount},\
    {"GetEquipmentItemCharge",                ItemFunctions::GetEquipmentItemCharge},\
    {"GetEquipmentItemEnchantmentCharge",     ItemFunctions::GetEquipmentItemEnchantmentCharge},\
    \
    {"GetInventoryItemRefId",                 ItemFunctions::GetInventoryItemRefId},\
    {"GetInventoryItemCount",                 ItemFunctions::GetInventoryItemCount},\
    {"GetInventoryItemCharge",                ItemFunctions::GetInventoryItemCharge},\
    {"GetInventoryItemEnchantmentCharge",     ItemFunctions::GetInventoryItemEnchantmentCharge},\
    \
    {"SendEquipment",                         ItemFunctions::SendEquipment},\
    {"SendInventoryChanges",                  ItemFunctions::SendInventoryChanges}

class ItemFunctions
{
public:

    /**
    * \brief Clear the last recorded inventory changes for a player.
    *
    * This is used to initialize the sending of new PlayerInventory packets.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \return void
    */
    static void InitializeInventoryChanges(unsigned short pid) noexcept;

    /**
    * \brief Get the number of slots used for equipment.
    *
    * The number is 19 before any dehardcoding is done in OpenMW.
    *
    * \return The number of slots.
    */
    static int GetEquipmentSize() noexcept;

    /**
    * \brief Get the number of indexes in a player's latest inventory changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \return The number of indexes.
    */
    static unsigned int GetInventoryChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Equip an item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The equipment slot.
    * \param refId The refId of the item.
    * \param count The count of the item.
    * \param charge The charge of the item.
    * \param enchantmentCharge The enchantment charge of the item.
    * \return void
    */
    static void EquipItem(unsigned short pid, unsigned short slot, const char* refId, unsigned int count, int charge, double enchantmentCharge = -1) noexcept;
    
    /**
    * \brief Unequip the item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The equipment slot.
    * \return void
    */
    static void UnequipItem(unsigned short pid, unsigned short slot) noexcept;

    /**
    * \brief Add an item to a player's inventory.
    *
    * Note: This will set the ADD action for all of the player's current inventory changes.
    *
    * \param pid The player ID.
    * \param refId The refId of the item.
    * \param count The count of the item.
    * \param charge The charge of the item.
    * \param enchantmentCharge The enchantment charge of the item.
    * \return void
    */
    static void AddItem(unsigned short pid, const char* refId, unsigned int count, int charge, double enchantmentCharge = -1) noexcept;

    /**
    * \brief Remove an item from a player's inventory.
    *
    * Note: This will set the REMOVE action for all of the player's current inventory changes.
    *
    * \param pid The player ID.
    * \param refId The refId of the item.
    * \param count The count of the item.
    * \return void
    */
    static void RemoveItem(unsigned short pid, const char* refId, unsigned short count) noexcept;

    /**
    * \brief Check whether a player has equipped an item with a certain refId in any slot.
    *
    * \param pid The player ID.
    * \param refId The refId of the item.
    * \return Whether the player has the item equipped.
    */
    static bool HasItemEquipped(unsigned short pid, const char* refId);

    /**
    * \brief Get the refId of the item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the equipment item.
    * \return The refId.
    */
    static const char *GetEquipmentItemRefId(unsigned short pid, unsigned short slot) noexcept;

    /**
    * \brief Get the count of the item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the equipment item.
    * \return The item count.
    */
    static int GetEquipmentItemCount(unsigned short pid, unsigned short slot) noexcept;

    /**
    * \brief Get the charge of the item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the equipment item.
    * \return The charge.
    */
    static int GetEquipmentItemCharge(unsigned short pid, unsigned short slot) noexcept;

    /**
    * \brief Get the enchantment charge of the item in a certain slot of the equipment of
    *        a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the equipment item.
    * \return The enchantment charge.
    */
    static double GetEquipmentItemEnchantmentCharge(unsigned short pid, unsigned short slot) noexcept;

    /**
    * \brief Get the refId of the item at a certain index in a player's latest inventory
    *        changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param i The index of the inventory item.
    * \return The refId.
    */
    static const char *GetInventoryItemRefId(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the count of the item at a certain index in a player's latest inventory
    *        changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param i The index of the inventory item.
    * \return The item count.
    */
    static int GetInventoryItemCount(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the charge of the item at a certain index in a player's latest inventory
    *        changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param i The index of the inventory item.
    * \return The charge.
    */
    static int GetInventoryItemCharge(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the enchantment charge of the item at a certain index in a player's
    *        latest inventory changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param i The index of the inventory item.
    * \return The enchantment charge.
    */
    static double GetInventoryItemEnchantmentCharge(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Send a PlayerEquipment packet with a player's equipment.
    *
    * It is always sent to all players.
    *
    * \param pid The player ID whose equipment should be sent.
    * \return void
    */
    static void SendEquipment(unsigned short pid) noexcept;

    /**
    * \brief Send a PlayerInventory packet with a player's recorded inventory changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param toOthers Whether this packet should be sent only to other players or
    *                 only to the player it is about.
    * \return void
    */
    static void SendInventoryChanges(unsigned short pid, bool toOthers = false) noexcept;
private:

};

#endif //OPENMW_ITEMAPI_HPP
