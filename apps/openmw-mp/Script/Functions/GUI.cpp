//
// Created by koncord on 23.07.16.
//

#include "GUI.hpp"

#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>

void GUIFunctions::_MessageBox(unsigned short pid, int id, const char *label) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.type = Player::GUIMessageBox::MessageBox;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::CustomMessageBox(unsigned short pid, int id, const char *label, const char *buttons) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.buttons = buttons;
    player->guiMessageBox.type = Player::GUIMessageBox::CustomMessageBox;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::InputDialog(unsigned short pid, int id, const char *label, const char *note) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.note = note;
    player->guiMessageBox.type = Player::GUIMessageBox::InputDialog;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::PasswordDialog(unsigned short pid, int id, const char *label, const char *note) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.note = note;
    player->guiMessageBox.type = Player::GUIMessageBox::PasswordDialog;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::ListBox(unsigned short pid, int id, const char *label, const char *items)
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.data = items;
    player->guiMessageBox.type = Player::GUIMessageBox::ListBox;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::InitializeQuickKeyChanges(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->quickKeyChanges.quickKeys.clear();
}

unsigned int GUIFunctions::GetQuickKeyChangesSize(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->quickKeyChanges.count;
}

int GUIFunctions::GetQuickKeySlot(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->quickKeyChanges.count)
        return 0;

    return player->quickKeyChanges.quickKeys.at(i).slot;
}

int GUIFunctions::GetQuickKeyType(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (i >= player->quickKeyChanges.count)
        return 0;

    return player->quickKeyChanges.quickKeys.at(i).type;
}

const char *GUIFunctions::GetQuickKeyItemId(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->quickKeyChanges.count)
        return "invalid";

    return player->quickKeyChanges.quickKeys.at(i).itemId.c_str();
}

void GUIFunctions::AddQuickKey(unsigned short pid, unsigned short slot, int type, const char* itemId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::QuickKey quickKey;
    quickKey.slot = slot;
    quickKey.type = type;
    quickKey.itemId = itemId;

    player->quickKeyChanges.quickKeys.push_back(quickKey);
}

void GUIFunctions::SendQuickKeyChanges(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_QUICKKEYS)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_QUICKKEYS)->Send(false);
}

void GUIFunctions::SetMapVisibility(unsigned short targetPid, unsigned short affectedPid, unsigned short state) noexcept
{
    LOG_MESSAGE(Log::LOG_WARN, "stub");
}

void GUIFunctions::SetMapVisibilityAll(unsigned short targetPid, unsigned short state) noexcept
{
    LOG_MESSAGE(Log::LOG_WARN, "stub");
}
