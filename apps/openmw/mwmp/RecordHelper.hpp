#ifndef OPENMW_RECORDHELPER_HPP
#define OPENMW_RECORDHELPER_HPP

#include <components/esm/loadcrea.hpp>
#include <components/esm/loadnpc.hpp>

namespace RecordHelper
{
    bool doesCreatureExist(const std::string& refId);
    bool doesRaceExist(const std::string& raceId);

    std::string createCreatureRecord(const ESM::Creature& creature);
    std::string createNpcRecord(const ESM::NPC& npc);

    void overrideCreatureRecord(const ESM::Creature& creature);
    void overrideNpcRecord(const ESM::NPC& npc);

    void overrideEnchantmentRecord(const ESM::Enchantment& enchantment);
    void overridePotionRecord(const ESM::Potion& potion);
    void overrideSpellRecord(const ESM::Spell& spell);
}


#endif //OPENMW_RECORDHELPER_HPP
