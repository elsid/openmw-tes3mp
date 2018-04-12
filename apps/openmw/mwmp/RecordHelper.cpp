#include <components/openmw-mp/Log.hpp>

#include "../mwbase/environment.hpp"

#include "../mwworld/worldimp.hpp"

#include "RecordHelper.hpp"

bool RecordHelper::doesCreatureExist(const std::string& refId)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    return world->getStore().get<ESM::Creature>().search(refId);
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

void RecordHelper::updateCreatureRecord(const ESM::Creature& creature)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    MWWorld::ESMStore *esmStore = const_cast<MWWorld::ESMStore *>(&world->getStore());
    MWWorld::Store<ESM::Creature> *creatureStore = const_cast<MWWorld::Store<ESM::Creature> *> (&esmStore->get<ESM::Creature>());

    creatureStore->insert(creature);
}

void RecordHelper::updateNpcRecord(const ESM::NPC& npc)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    MWWorld::ESMStore *esmStore = const_cast<MWWorld::ESMStore *>(&world->getStore());
    MWWorld::Store<ESM::NPC> *npcStore = const_cast<MWWorld::Store<ESM::NPC> *> (&esmStore->get<ESM::NPC>());

    npcStore->insert(npc);
}
