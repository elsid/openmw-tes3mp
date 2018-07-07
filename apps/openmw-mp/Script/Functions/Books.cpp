#include "Books.hpp"

#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>

using namespace mwmp;

void BookFunctions::InitializeBookChanges(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    return player->bookChanges.books.clear();
}

unsigned int BookFunctions::GetBookChangesSize(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->bookChanges.count;
}

void BookFunctions::AddBook(unsigned short pid, const char* bookId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::Book book;
    book.bookId = bookId;

    player->bookChanges.books.push_back(book);
}

const char *BookFunctions::GetBookId(unsigned short pid, unsigned int i) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (i >= player->bookChanges.count)
        return "invalid";

    return player->bookChanges.books.at(i).bookId.c_str();
}

void BookFunctions::SendBookChanges(unsigned short pid, bool sendToOtherPlayers, bool sendToAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_BOOK);

    packet->setPlayer(player);

    if (sendToAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}
