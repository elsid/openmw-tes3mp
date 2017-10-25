//
// Created by koncord on 30.08.16.
//

#ifndef OPENMW_GUIAPI_HPP
#define OPENMW_GUIAPI_HPP

#define GUIAPI \
    {"MessageBox",                 GUIFunctions::_MessageBox},\
    {"CustomMessageBox",           GUIFunctions::CustomMessageBox},\
    {"InputDialog",                GUIFunctions::InputDialog},\
    {"PasswordDialog",             GUIFunctions::PasswordDialog},\
    {"ListBox",                    GUIFunctions::ListBox},\
    \
    {"InitializeQuickKeyChanges",  GUIFunctions::InitializeQuickKeyChanges},\
    \
    {"GetQuickKeyChangesSize",     GUIFunctions::GetQuickKeyChangesSize},\
    \
    {"GetQuickKeySlot",            GUIFunctions::GetQuickKeySlot},\
    {"GetQuickKeyType",            GUIFunctions::GetQuickKeyType},\
    {"GetQuickKeyItemId",          GUIFunctions::GetQuickKeyItemId},\
    \
    {"AddQuickKey",                GUIFunctions::AddQuickKey},\
    \
    {"SendQuickKeyChanges",        GUIFunctions::SendQuickKeyChanges},\
    \
    {"SetMapVisibility",           GUIFunctions::SetMapVisibility},\
    {"SetMapVisibilityAll",        GUIFunctions::SetMapVisibilityAll}

class GUIFunctions
{
public:
    /* Do not rename into MessageBox to not conflict with WINAPI's MessageBox */
    static void _MessageBox(unsigned short pid, int id, const char *label) noexcept;

    static void CustomMessageBox(unsigned short pid, int id, const char *label, const char *buttons) noexcept;
    static void InputDialog(unsigned short pid, int id, const char *label) noexcept;
    static void PasswordDialog(unsigned short pid, int id, const char *label, const char *note) noexcept;

    static void ListBox(unsigned short pid, int id, const char *label, const char *items);

    /**
    * \brief Clear the last recorded quick key changes for a player.
    *
    * This is used to initialize the sending of new PlayerQuickKeys packets.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \return void
    */
    static void InitializeQuickKeyChanges(unsigned short pid) noexcept;

    /**
    * \brief Get the number of indexes in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \return The number of indexes.
    */
    static unsigned int GetQuickKeyChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Add a new quick key to the quick key changes for a player.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param slot The slot to be used.
    * \param slot The type of the quick key (0 for ITEM, 1 for ITEM_MAGIC, 2 for MAGIC, 3 for UNASSIGNED).
    * \param itemId The itemId of the item.
    * \return void
    */
    static void AddQuickKey(unsigned short pid, unsigned short slot, int type, const char* itemId = "") noexcept;

    /**
    * \brief Get the slot of the quick key at a certain index in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param i The index of the quick key in the quick key changes vector.
    * \return The slot.
    */
    static int GetQuickKeySlot(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the type of the quick key at a certain index in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param i The index of the quick key in the quick key changes vector.
    * \return The quick key type.
    */
    static int GetQuickKeyType(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Get the itemId at a certain index in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param i The index of the quick key in the quick key changes vector.
    * \return The itemId.
    */
    static const char *GetQuickKeyItemId(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Send a PlayerQuickKeys packet with a player's recorded quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \return void
    */
    static void SendQuickKeyChanges(unsigned short pid) noexcept;

    //state 0 - disallow, 1 - allow
    static void SetMapVisibility(unsigned short targetPID, unsigned short affectedPID, unsigned short state) noexcept;
    static void SetMapVisibilityAll(unsigned short targetPID, unsigned short state) noexcept;
};

#endif //OPENMW_GUIAPI_HPP
