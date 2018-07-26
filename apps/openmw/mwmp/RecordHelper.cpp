#include <components/openmw-mp/Log.hpp>

#include "../mwbase/environment.hpp"

#include "../mwworld/worldimp.hpp"

#include "RecordHelper.hpp"

bool RecordHelper::doesCreatureExist(const std::string& refId)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    return world->getStore().get<ESM::Creature>().search(refId);
}

bool RecordHelper::doesNpcExist(const std::string& refId)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    return world->getStore().get<ESM::NPC>().search(refId);
}

bool RecordHelper::doesRaceExist(const std::string& raceId)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    return world->getStore().get<ESM::Race>().search(raceId);
}

std::string RecordHelper::createCreatureRecord(const ESM::Creature& creature)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    return world->createRecord(creature)->mId;
}

std::string RecordHelper::createNpcRecord(const ESM::NPC& npc)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    return world->createRecord(npc)->mId;
}

void RecordHelper::overrideCreatureRecord(const ESM::Creature& creature)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    world->getModifiableStore().overrideRecord(creature);
}

void RecordHelper::overrideNpcRecord(const ESM::NPC& npc)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    world->getModifiableStore().overrideRecord(npc);
}

void RecordHelper::overrideEnchantmentRecord(const ESM::Enchantment& enchantment)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    world->getModifiableStore().overrideRecord(enchantment);
}

void RecordHelper::overridePotionRecord(const ESM::Potion& potion)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    world->getModifiableStore().overrideRecord(potion);
}

void RecordHelper::overrideSpellRecord(const ESM::Spell& spell)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    world->getModifiableStore().overrideRecord(spell);
}
