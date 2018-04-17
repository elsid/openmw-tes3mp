#ifndef OPENMW_MECHANICSAPI_HPP
#define OPENMW_MECHANICSAPI_HPP

#include "../Types.hpp"

#define MECHANICSAPI \
    {"GetMiscellaneousChangeType", MechanicsFunctions::GetMiscellaneousChangeType},\
    \
    {"GetMarkCell",                 MechanicsFunctions::GetMarkCell},\
    {"GetMarkPosX",                 MechanicsFunctions::GetMarkPosX},\
    {"GetMarkPosY",                 MechanicsFunctions::GetMarkPosY},\
    {"GetMarkPosZ",                 MechanicsFunctions::GetMarkPosZ},\
    {"GetMarkRotX",                 MechanicsFunctions::GetMarkRotX},\
    {"GetMarkRotZ",                 MechanicsFunctions::GetMarkRotZ},\
    {"GetSelectedSpellId",          MechanicsFunctions::GetSelectedSpellId},\
    \
    {"GetScale",                    MechanicsFunctions::GetScale},\
    {"IsWerewolf",                  MechanicsFunctions::IsWerewolf},\
    {"GetCreatureRefId",            MechanicsFunctions::GetCreatureRefId},\
    {"GetCreatureNameDisplayState", MechanicsFunctions::GetCreatureNameDisplayState},\
    \
    {"SetMarkCell",                 MechanicsFunctions::SetMarkCell},\
    {"SetMarkPos",                  MechanicsFunctions::SetMarkPos},\
    {"SetMarkRot",                  MechanicsFunctions::SetMarkRot},\
    {"SetSelectedSpellId",          MechanicsFunctions::SetSelectedSpellId},\
    \
    {"SetScale",                    MechanicsFunctions::SetScale},\
    {"SetWerewolfState",            MechanicsFunctions::SetWerewolfState},\
    {"SetCreatureRefId",            MechanicsFunctions::SetCreatureRefId},\
    {"SetCreatureNameDisplayState", MechanicsFunctions::SetCreatureNameDisplayState},\
    \
    {"SendMarkLocation",            MechanicsFunctions::SendMarkLocation},\
    {"SendSelectedSpell",           MechanicsFunctions::SendSelectedSpell},\
    {"SendShapeshift",              MechanicsFunctions::SendShapeshift},\
    \
    {"Jail",                        MechanicsFunctions::Jail},\
    {"Resurrect",                   MechanicsFunctions::Resurrect}

class MechanicsFunctions
{
public:

    /**
    * \brief Get the type of a PlayerMiscellaneous packet.
    *
    * \param pid The player ID.
    * \return The type.
    */
    static unsigned char GetMiscellaneousChangeType(unsigned short pid) noexcept;

    /**
    * \brief Get the cell description of a player's Mark cell.
    *
    * \param pid The player ID.
    * \return The cell description.
    */
    static const char *GetMarkCell(unsigned short pid) noexcept;

    /**
    * \brief Get the X position of a player's Mark.
    *
    * \param pid The player ID.
    * \return The X position.
    */
    static double GetMarkPosX(unsigned short pid) noexcept;

    /**
    * \brief Get the Y position of a player's Mark.
    *
    * \param pid The player ID.
    * \return The Y position.
    */
    static double GetMarkPosY(unsigned short pid) noexcept;

    /**
    * \brief Get the Z position of a player's Mark.
    *
    * \param pid The player ID.
    * \return The Z position.
    */
    static double GetMarkPosZ(unsigned short pid) noexcept;

    /**
    * \brief Get the X rotation of a player's Mark.
    *
    * \param pid The player ID.
    * \return The X rotation.
    */
    static double GetMarkRotX(unsigned short pid) noexcept;

    /**
    * \brief Get the Z rotation of a player's Mark.
    *
    * \param pid The player ID.
    * \return The X rotation.
    */
    static double GetMarkRotZ(unsigned short pid) noexcept;

    /**
    * \brief Get the ID of a player's selected spell.
    *
    * \param pid The player ID.
    * \return The spell ID.
    */
    static const char *GetSelectedSpellId(unsigned short pid) noexcept;

    /**
    * \brief Get the scale of a player.
    *
    * \param pid The player ID.
    * \return The scale.
    */
    static double GetScale(unsigned short pid) noexcept;

    /**
    * \brief Check whether a player is a werewolf.
    *
    * This is based on the last PlayerShapeshift packet received or sent for that player.
    *
    * \param pid The player ID.
    * \return The werewolf state.
    */
    static bool IsWerewolf(unsigned short pid) noexcept;

    /**
    * \brief Get the refId of the creature the player is disguised as.
    *
    * \param pid The player ID.
    * \return The creature refId.
    */
    static const char *GetCreatureRefId(unsigned short pid) noexcept;

    /**
    * \brief Check whether a player's name is replaced by that of the creature they are
    *        disguised as when other players hover over them.
    *
    * This is based on the last PlayerShapeshift packet received or sent for that player.
    *
    * \param pid The player ID.
    * \return The creature name display state.
    */
    static bool GetCreatureNameDisplayState(unsigned short pid) noexcept;

    /**
    * \brief Set the Mark cell of a player.
    *
    * This changes the Mark cell recorded for that player in the server memory, but does not by itself
    * send a packet.
    *
    * The cell is determined to be an exterior cell if it fits the pattern of a number followed
    * by a comma followed by another number.
    *
    * \param pid The player ID.
    * \param cellDescription The cell description.
    * \return void
    */
    static void SetMarkCell(unsigned short pid, const char *cellDescription) noexcept;

    /**
    * \brief Set the Mark position of a player.
    *
    * This changes the Mark positional coordinates recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param x The X position.
    * \param y The Y position.
    * \param z The Z position.
    * \return void
    */
    static void SetMarkPos(unsigned short pid, double x, double y, double z) noexcept;

    /**
    * \brief Set the Mark rotation of a player.
    *
    * This changes the Mark positional coordinates recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param x The X rotation.
    * \param z The Z rotation.
    * \return void
    */
    static void SetMarkRot(unsigned short pid, double x, double z) noexcept;

    /**
    * \brief Set the ID of a player's selected spell.
    *
    * This changes the spell ID recorded for that player in the server memory, but does not by itself
    * send a packet.
    *
    * \param pid The player ID.
    * \param spellId The spell ID.
    * \return void
    */
    static void SetSelectedSpellId(unsigned short pid, const char *spellId) noexcept;

    /**
    * \brief Set the scale of a player.
    *
    * This changes the scale recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param scale The new scale.
    * \return void
    */
    static void SetScale(unsigned short pid, double scale) noexcept;

    /**
    * \brief Set the werewolf state of a player.
    *
    * This changes the werewolf state recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param isWerewolf The new werewolf state.
    * \return void
    */
    static void SetWerewolfState(unsigned short pid, bool isWerewolf) noexcept;

    /**
    * \brief Set the refId of the creature a player is disguised as.
    *
    * This changes the creature refId recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param refId The creature refId.
    * \param displaysCreatureName Whether the player's name appears as that of the creature
    *                             when hovered over by others.
    * \return void
    */
    static void SetCreatureRefId(unsigned short pid, const char *refId) noexcept;

    /**
    * \brief Set whether a player's name is replaced by that of the creature they are
    *        disguised as when other players hover over them.
    *
    * \param pid The player ID.
    * \param displayState The creature name display state.
    * \return void
    */
    static void SetCreatureNameDisplayState(unsigned short pid, bool displayState) noexcept;

    /**
    * \brief Send a PlayerMiscellaneous packet with a Mark location to a player.
    *
    * \param pid The player ID.
    * \return void
    */
    static void SendMarkLocation(unsigned short pid);

    /**
    * \brief Send a PlayerMiscellaneous packet with a selected spell ID to a player.
    *
    * \param pid The player ID.
    * \return void
    */
    static void SendSelectedSpell(unsigned short pid);

    /**
    * \brief Send a PlayerShapeshift packet about a player.
    *
    * This sends the packet to all players connected to the server. It is currently used
    * only to communicate werewolf states.
    *
    * \param pid The player ID.
    * \return void
    */
    static void SendShapeshift(unsigned short pid);

    /**
    * \brief Send a PlayerJail packet about a player.
    *
    * This is similar to the player being jailed by a guard, but provides extra parameters for
    * increased flexibility.
    *
    * It is only sent to the player being jailed, as the other players will be informed of the
    * jailing's actual consequences via other packets sent by the affected client.
    *
    * \param pid The player ID.
    * \param jailDays The number of days to spend jailed, where each day affects one skill point.
    * \param ignoreJailTeleportation Whether the player being teleported to the nearest jail
    *                                marker should be overridden.
    * \param ignoreJailSkillIncrease Whether the player's Sneak and Security skills should be
    *                                prevented from increasing as a result of the jailing,
    *                                overriding default behavior.
    * \param jailProgressText The text that should be displayed while jailed.
    * \param jailEndText The text that should be displayed once the jailing period is over.
    * \return void
    */
    static void Jail(unsigned short pid, int jailDays, bool ignoreJailTeleportation = false, bool ignoreJailSkillIncreases = false,
                     const char* jailProgressText = "", const char* jailEndText = "") noexcept;

    /**
    * \brief Send a PlayerResurrect packet about a player.
    *
    * This sends the packet to all players connected to the server.
    *
    * \param pid The player ID.
    * \param type The type of resurrection (0 for REGULAR, 1 for IMPERIAL_SHRINE,
    *             2 for TRIBUNAL_TEMPLE).
    * \return void
    */
    static void Resurrect(unsigned short pid, unsigned int type) noexcept;
};

#endif //OPENMW_MECHANICSAPI_HPP
