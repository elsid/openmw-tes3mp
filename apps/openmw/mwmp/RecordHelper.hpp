#ifndef OPENMW_RECORDHELPER_HPP
#define OPENMW_RECORDHELPER_HPP

#include <components/openmw-mp/Base/BaseWorldstate.hpp>

#include <components/esm/loadcrea.hpp>
#include <components/esm/loadnpc.hpp>

namespace RecordHelper
{
    bool doesClassRecordExist(const std::string& id);
    bool doesRaceRecordExist(const std::string& id);

    bool doesCreatureRecordExist(const std::string& id);
    bool doesNpcRecordExist(const std::string& id);

    bool doesEnchantmentRecordExist(const std::string& id);
    bool doesPotionRecordExist(const std::string& id);
    bool doesSpellRecordExist(const std::string& id);

    bool doesArmorRecordExist(const std::string& id);
    bool doesBookRecordExist(const std::string& id);
    bool doesClothingRecordExist(const std::string& id);
    bool doesMiscellaneousRecordExist(const std::string& id);
    bool doesWeaponRecordExist(const std::string& id);

    bool doesContainerRecordExist(const std::string& id);
    bool doesDoorRecordExist(const std::string& id);

    bool doesActivatorRecordExist(const std::string& id);
    bool doesStaticRecordExist(const std::string& id);

    std::string createCreatureRecord(const ESM::Creature& record);
    std::string createNpcRecord(const ESM::NPC& record);

    void overrideCreatureRecord(const mwmp::CreatureRecord& record);
    void overrideNpcRecord(const mwmp::NpcRecord& record);

    void overrideEnchantmentRecord(const mwmp::EnchantmentRecord& record);
    void overridePotionRecord(const mwmp::PotionRecord& record);
    void overrideSpellRecord(const mwmp::SpellRecord& record);

    void overrideArmorRecord(const mwmp::ArmorRecord& record);
    void overrideBookRecord(const mwmp::BookRecord& record);
    void overrideClothingRecord(const mwmp::ClothingRecord& record);
    void overrideMiscellaneousRecord(const mwmp::MiscellaneousRecord& record);
    void overrideWeaponRecord(const mwmp::WeaponRecord& record);

    void overrideContainerRecord(const mwmp::ContainerRecord& record);
    void overrideDoorRecord(const mwmp::DoorRecord& record);

    void overrideActivatorRecord(const mwmp::ActivatorRecord& record);
    void overrideStaticRecord(const mwmp::StaticRecord& record);

    void overrideCreatureRecord(const ESM::Creature& record);
    void overrideNpcRecord(const ESM::NPC& record);

    void overrideEnchantmentRecord(const ESM::Enchantment& record);
    void overridePotionRecord(const ESM::Potion& record);
    void overrideSpellRecord(const ESM::Spell& record);

    void overrideArmorRecord(const ESM::Armor& record);
    void overrideBookRecord(const ESM::Book& record);
    void overrideClothingRecord(const ESM::Clothing& record);
    void overrideMiscellaneousRecord(const ESM::Miscellaneous& record);
    void overrideWeaponRecord(const ESM::Weapon& record);

    void overrideContainerRecord(const ESM::Container& record);
    void overrideDoorRecord(const ESM::Door& record);

    void overrideActivatorRecord(const ESM::Activator& record);
    void overrideStaticRecord(const ESM::Static& record);
}


#endif //OPENMW_RECORDHELPER_HPP
