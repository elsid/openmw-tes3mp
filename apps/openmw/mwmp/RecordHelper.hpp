#ifndef OPENMW_RECORDHELPER_HPP
#define OPENMW_RECORDHELPER_HPP

#include <components/openmw-mp/Base/BaseWorldstate.hpp>

#include "../mwbase/environment.hpp"

namespace RecordHelper
{
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

    template<class RecordType>
    const RecordType *createRecord(const RecordType &record)
    {
        MWBase::World *world = MWBase::Environment::get().getWorld();

        return world->createRecord(record);
    }

    template<class RecordType>
    bool doesRecordIdExist(const std::string& id)
    {
        MWBase::World *world = MWBase::Environment::get().getWorld();

        return world->getStore().get<RecordType>().search(id);
    }
}


#endif //OPENMW_RECORDHELPER_HPP
