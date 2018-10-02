#include "Books.hpp"

#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>

using namespace mwmp;

void BookFunctions::ClearBookChanges(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->bookChanges.books.clear();
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

const char *BookFunctions::GetBookId(unsigned short pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->bookChanges.count)
        return "invalid";

    return player->bookChanges.books.at(index).bookId.c_str();
}

void BookFunctions::SendBookChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_BOOK);

    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

// All methods below are deprecated versions of methods from above

void BookFunctions::InitializeBookChanges(unsigned short pid) noexcept
{
    ClearBookChanges(pid);
}
