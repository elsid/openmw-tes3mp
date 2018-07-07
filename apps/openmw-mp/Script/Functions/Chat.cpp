#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

void ScriptFunctions::SendMessage(unsigned short pid, const char *message, bool sendToOtherPlayers, bool sendToAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->chatMessage = message;

    LOG_MESSAGE_SIMPLE(Log::LOG_VERBOSE, "System: %s", message);

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_CHAT_MESSAGE);
    packet->setPlayer(player);

    if (sendToAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

void ScriptFunctions::CleanChatForPid(unsigned short pid)
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->chatMessage.clear();

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_CHAT_MESSAGE);
    packet->setPlayer(player);

    packet->Send(false);
}

void ScriptFunctions::CleanChat()
{
    for (auto player : *Players::getPlayers())
    {
        player.second->chatMessage.clear();

        mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_CHAT_MESSAGE);
        packet->setPlayer(player.second);

        packet->Send(false);
    }
}
