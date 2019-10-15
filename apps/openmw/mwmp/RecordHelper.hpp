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

    bool doesIngredientRecordExist(const std::string& id);
    bool doesApparatusRecordExist(const std::string& id);
    bool doesLockpickRecordExist(const std::string& id);
    bool doesProbeRecordExist(const std::string& id);
    bool doesRepairRecordExist(const std::string& id);
    bool doesLightRecordExist(const std::string& id);
    bool doesCellRecordExist(const std::string& id);

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

    void overrideIngredientRecord(const mwmp::IngredientRecord& record);
    void overrideApparatusRecord(const mwmp::ApparatusRecord& record);
    void overrideLockpickRecord(const mwmp::LockpickRecord& record);
    void overrideProbeRecord(const mwmp::ProbeRecord& record);
    void overrideRepairRecord(const mwmp::RepairRecord& record);
    void overrideLightRecord(const mwmp::LightRecord& record);
    void overrideCellRecord(const mwmp::CellRecord& record);

    template<class RecordType>
    void overrideRecord(const RecordType &record)
    {
        MWBase::World *world = MWBase::Environment::get().getWorld();

        world->getModifiableStore().overrideRecord(record);
    }
}


#endif //OPENMW_RECORDHELPER_HPP
