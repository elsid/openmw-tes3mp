#ifndef OPENMW_BOOKAPI_HPP
#define OPENMW_BOOKAPI_HPP

#define BOOKAPI \
    {"InitializeBookChanges",  BookFunctions::InitializeBookChanges},\
    \
    {"GetBookChangesSize",     BookFunctions::GetBookChangesSize},\
    \
    {"AddBook",                BookFunctions::AddBook},\
    \
    {"GetBookId",              BookFunctions::GetBookId},\
    \
    {"SendBookChanges",        BookFunctions::SendBookChanges}

class BookFunctions
{
public:

    /**
    * \brief Clear the last recorded book changes for a player.
    *
    * This is used to initialize the sending of new PlayerBook packets.
    *
    * \param pid The player ID whose book changes should be used.
    * \return void
    */
    static void InitializeBookChanges(unsigned short pid) noexcept;

    /**
    * \brief Get the number of indexes in a player's latest book changes.
    *
    * \param pid The player ID whose book changes should be used.
    * \return The number of indexes.
    */
    static unsigned int GetBookChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Add a new book to the book changes for a player.
    *
    * \param pid The player ID whose book changes should be used.
    * \param bookId The bookId of the book.
    * \return void
    */
    static void AddBook(unsigned short pid, const char* bookId) noexcept;

    /**
    * \brief Get the bookId at a certain index in a player's latest book changes.
    *
    * \param pid The player ID whose book changes should be used.
    * \param i The index of the book.
    * \return The bookId.
    */
    static const char *GetBookId(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Send a PlayerBook packet with a player's recorded book changes.
    *
    * \param pid The player ID whose book changes should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param sendToAttachedPlayer Whether the packet should be sent to the player attached
    *                             to the packet (true by default).
    * \return void
    */
    static void SendBookChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

private:

};

#endif //OPENMW_BOOKAPI_HPP
