#ifndef OPENMW_DIALOGUEAPI_HPP
#define OPENMW_DIALOGUEAPI_HPP

#define DIALOGUEAPI \
    {"InitializeTopicChanges",  DialogueFunctions::InitializeTopicChanges},\
    \
    {"GetTopicChangesSize",     DialogueFunctions::GetTopicChangesSize},\
    \
    {"AddTopic",                DialogueFunctions::AddTopic},\
    \
    {"GetTopicId",              DialogueFunctions::GetTopicId},\
    \
    {"SendTopicChanges",        DialogueFunctions::SendTopicChanges},\
    \
    {"PlayAnimation",           DialogueFunctions::PlayAnimation},\
    {"PlaySpeech",              DialogueFunctions::PlaySpeech}

class DialogueFunctions
{
public:

    /**
    * \brief Clear the last recorded topic changes for a player.
    *
    * This is used to initialize the sending of new PlayerTopic packets.
    *
    * \param pid The player ID whose topic changes should be used.
    * \return void
    */
    static void InitializeTopicChanges(unsigned short pid) noexcept;

    /**
    * \brief Get the number of indexes in a player's latest topic changes.
    *
    * \param pid The player ID whose topic changes should be used.
    * \return The number of indexes.
    */
    static unsigned int GetTopicChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Add a new topic to the topic changes for a player.
    *
    * \param pid The player ID whose topic changes should be used.
    * \param topicId The topicId of the topic.
    * \return void
    */
    static void AddTopic(unsigned short pid, const char* topicId) noexcept;

    /**
    * \brief Get the topicId at a certain index in a player's latest topic changes.
    *
    * \param pid The player ID whose topic changes should be used.
    * \param i The index of the topic.
    * \return The topicId.
    */
    static const char *GetTopicId(unsigned short pid, unsigned int i) noexcept;

    /**
    * \brief Send a PlayerTopic packet with a player's recorded topic changes.
    *
    * \param pid The player ID whose topic changes should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param sendToAttachedPlayer Whether the packet should be sent to the player attached
    *                             to the packet (true by default).
    * \return void
    */
    static void SendTopicChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    static void PlayAnimation(unsigned short pid, const char* groupname, int mode = 0, int count = 1, bool persist = false) noexcept;
    static void PlaySpeech(unsigned short pid, const char* sound) noexcept;

private:

};

#endif //OPENMW_DIALOGUEAPI_HPP
