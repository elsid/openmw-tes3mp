#include "Quests.hpp"

#include <components/misc/stringops.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>

using namespace mwmp;

void QuestFunctions::InitializeJournalChanges(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->journalChanges.journalItems.clear();
}

void QuestFunctions::InitializeKillChanges(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->killChanges.kills.clear();
}

unsigned int QuestFunctions::GetJournalChangesSize(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->journalChanges.count;
}

unsigned int QuestFunctions::GetKillChangesSize(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->killChanges.count;
}

void QuestFunctions::AddJournalEntry(unsigned short pid, const char* quest, unsigned int index, const char* actorRefId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::JournalItem journalItem;
    journalItem.type = JournalItem::ENTRY;
    journalItem.quest = quest;
    journalItem.index = index;
    journalItem.actorRefId = actorRefId;

    player->journalChanges.journalItems.push_back(journalItem);
}

void QuestFunctions::AddJournalIndex(unsigned short pid, const char* quest, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::JournalItem journalItem;
    journalItem.type = JournalItem::INDEX;
    journalItem.quest = quest;
    journalItem.index = index;

    player->journalChanges.journalItems.push_back(journalItem);
}

void QuestFunctions::AddKill(unsigned short pid, const char* refId, int number) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::Kill kill;
    kill.refId = refId;
    kill.number = number;

    player->killChanges.kills.push_back(kill);
}

void QuestFunctions::SetReputation(unsigned short pid, int value) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->npcStats.mReputation = value;
}

const char *QuestFunctions::GetJournalItemQuest(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->journalChanges.count)
        return "invalid";

    return player->journalChanges.journalItems.at(i).quest.c_str();
}

int QuestFunctions::GetJournalItemIndex(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->journalChanges.journalItems.at(i).index;
}

int QuestFunctions::GetJournalItemType(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->journalChanges.journalItems.at(i).type;
}

const char *QuestFunctions::GetJournalItemActorRefId(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->journalChanges.journalItems.at(i).actorRefId.c_str();
}

const char *QuestFunctions::GetKillRefId(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->killChanges.count)
        return "invalid";

    return player->killChanges.kills.at(i).refId.c_str();
}

int QuestFunctions::GetKillNumber(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->killChanges.kills.at(i).number;
}

int QuestFunctions::GetReputation(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->npcStats.mReputation;
}

void QuestFunctions::SendJournalChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_JOURNAL);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

void QuestFunctions::SendKillChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_KILL_COUNT);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

void QuestFunctions::SendReputation(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_REPUTATION);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}
