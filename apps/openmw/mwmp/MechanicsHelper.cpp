#include <components/openmw-mp/Log.hpp>

#include <components/misc/rng.hpp>

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"

#include "../mwmechanics/creaturestats.hpp"
#include "../mwmechanics/combat.hpp"
#include "../mwmechanics/levelledlist.hpp"
#include "../mwmechanics/spellcasting.hpp"

#include "../mwworld/class.hpp"
#include "../mwworld/inventorystore.hpp"

#include "MechanicsHelper.hpp"
#include "Main.hpp"
#include "Networking.hpp"
#include "LocalPlayer.hpp"
#include "DedicatedPlayer.hpp"
#include "PlayerList.hpp"
#include "ObjectList.hpp"
#include "CellController.hpp"

using namespace mwmp;

osg::Vec3f MechanicsHelper::getLinearInterpolation(osg::Vec3f start, osg::Vec3f end, float percent)
{
    osg::Vec3f position(percent, percent, percent);

    return (start + osg::componentMultiply(position, (end - start)));
}

ESM::Position MechanicsHelper::getPositionFromVector(osg::Vec3f vector)
{
    ESM::Position position;
    position.pos[0] = vector.x();
    position.pos[1] = vector.y();
    position.pos[2] = vector.z();

    return position;
}

// Inspired by similar code in mwclass\creaturelevlist.cpp
void MechanicsHelper::spawnLeveledCreatures(MWWorld::CellStore* cellStore)
{
    MWWorld::CellRefList<ESM::CreatureLevList> *creatureLevList = cellStore->getCreatureLists();
    mwmp::ObjectList *objectList = mwmp::Main::get().getNetworking()->getObjectList();
    objectList->reset();
    objectList->packetOrigin = mwmp::CLIENT_GAMEPLAY;

    int spawnCount = 0;

    for (auto &lref : creatureLevList->mList)
    {
        MWWorld::Ptr ptr(&lref, cellStore);

        std::string id = MWMechanics::getLevelledItem(ptr.get<ESM::CreatureLevList>()->mBase, true);

        if (!id.empty())
        {
            const MWWorld::ESMStore& store = MWBase::Environment::get().getWorld()->getStore();
            MWWorld::ManualRef manualRef(store, id);
            manualRef.getPtr().getCellRef().setPosition(ptr.getCellRef().getPosition());
            MWWorld::Ptr placed = MWBase::Environment::get().getWorld()->placeObject(manualRef.getPtr(), ptr.getCell(),
                                                                                     ptr.getCellRef().getPosition());
            objectList->addObjectSpawn(placed);
            MWBase::Environment::get().getWorld()->deleteObject(placed);

            spawnCount++;
        }
    }

    if (spawnCount > 0)
        objectList->sendObjectSpawn();
}

Attack *MechanicsHelper::getLocalAttack(const MWWorld::Ptr& ptr)
{
    if (ptr == MWBase::Environment::get().getWorld()->getPlayerPtr())
        return &mwmp::Main::get().getLocalPlayer()->attack;
    else if (mwmp::Main::get().getCellController()->isLocalActor(ptr))
        return &mwmp::Main::get().getCellController()->getLocalActor(ptr)->attack;

    return nullptr;
}

Attack *MechanicsHelper::getDedicatedAttack(const MWWorld::Ptr& ptr)
{
    if (mwmp::PlayerList::isDedicatedPlayer(ptr))
        return &mwmp::PlayerList::getPlayer(ptr)->attack;
    else if (mwmp::Main::get().getCellController()->isDedicatedActor(ptr))
        return &mwmp::Main::get().getCellController()->getDedicatedActor(ptr)->attack;

    return nullptr;
}

MWWorld::Ptr MechanicsHelper::getPlayerPtr(const Target& target)
{
    if (target.guid == mwmp::Main::get().getLocalPlayer()->guid)
        return MWBase::Environment::get().getWorld()->getPlayerPtr();
    else if (PlayerList::getPlayer(target.guid) != nullptr)
        return PlayerList::getPlayer(target.guid)->getPtr();

    return nullptr;
}

mwmp::Target MechanicsHelper::getTarget(const MWWorld::Ptr& ptr)
{
    mwmp::Target target;
    clearTarget(target);

    if (ptr != nullptr)
    {
        if (ptr == MWBase::Environment::get().getWorld()->getPlayerPtr())
        {
            target.isPlayer = true;
            target.guid = mwmp::Main::get().getLocalPlayer()->guid;
        }
        else if (mwmp::PlayerList::isDedicatedPlayer(ptr))
        {
            target.isPlayer = true;
            target.guid = mwmp::PlayerList::getPlayer(ptr)->guid;
        }
        else
        {
            MWWorld::CellRef *ptrRef = &ptr.getCellRef();

            if (ptrRef)
            {
                target.isPlayer = false;
                target.refId = ptrRef->getRefId();
                target.refNum = ptrRef->getRefNum().mIndex;
                target.mpNum = ptrRef->getMpNum();
                target.name = ptr.getClass().getName(ptr);
            }
        }
    }

    return target;
}

void MechanicsHelper::clearTarget(mwmp::Target& target)
{
    target.isPlayer = false;
    target.refId.clear();
    target.refNum = -1;
    target.mpNum = -1;

    target.name.clear();
}

bool MechanicsHelper::isEmptyTarget(const mwmp::Target& target)
{
    if (target.isPlayer == false && target.refId.empty())
        return true;

    return false;
}

void MechanicsHelper::assignAttackTarget(Attack* attack, const MWWorld::Ptr& target)
{
    if (target == MWBase::Environment::get().getWorld()->getPlayerPtr())
    {
        attack->target.isPlayer = true;
        attack->target.guid = mwmp::Main::get().getLocalPlayer()->guid;
    }
    else if (mwmp::PlayerList::isDedicatedPlayer(target))
    {
        attack->target.isPlayer = true;
        attack->target.guid = mwmp::PlayerList::getPlayer(target)->guid;
    }
    else
    {
        MWWorld::CellRef *targetRef = &target.getCellRef();

        attack->target.isPlayer = false;
        attack->target.refId = targetRef->getRefId();
        attack->target.refNum = targetRef->getRefNum().mIndex;
        attack->target.mpNum = targetRef->getMpNum();
    }
}

void MechanicsHelper::resetAttack(Attack* attack)
{
    attack->success = false;
    attack->knockdown = false;
    attack->block = false;
    attack->applyWeaponEnchantment = false;
    attack->applyProjectileEnchantment = false;
    attack->target.guid = RakNet::RakNetGUID();
    attack->target.refId.clear();
    attack->target.refNum = 0;
    attack->target.mpNum = 0;
}

bool MechanicsHelper::getSpellSuccess(std::string spellId, const MWWorld::Ptr& caster)
{
    return Misc::Rng::roll0to99() < MWMechanics::getSpellSuccessChance(spellId, caster);
}

void MechanicsHelper::processAttack(Attack attack, const MWWorld::Ptr& attacker)
{
    if (!attack.pressed)
    {
        LOG_MESSAGE_SIMPLE(Log::LOG_VERBOSE, "Processing attack from %s",
            attacker.getCellRef().getRefId().c_str());
        LOG_APPEND(Log::LOG_VERBOSE, "- success: %s", attack.success ? "true" : "false");

        if (attack.success)
            LOG_APPEND(Log::LOG_VERBOSE, "- damage: %f", attack.damage);
    }

    MWMechanics::CreatureStats &attackerStats = attacker.getClass().getCreatureStats(attacker);
    MWWorld::Ptr victim;

    if (attack.target.isPlayer)
    {
        if (attack.target.guid == mwmp::Main::get().getLocalPlayer()->guid)
            victim = MWBase::Environment::get().getWorld()->getPlayerPtr();
        else if (PlayerList::getPlayer(attack.target.guid) != nullptr)
            victim = PlayerList::getPlayer(attack.target.guid)->getPtr();
    }
    else
    {
        auto controller = mwmp::Main::get().getCellController();
        if (controller->isLocalActor(attack.target.refNum, attack.target.mpNum))
            victim = controller->getLocalActor(attack.target.refNum, attack.target.mpNum)->getPtr();
        else if (controller->isDedicatedActor(attack.target.refNum, attack.target.mpNum))
            victim = controller->getDedicatedActor(attack.target.refNum, attack.target.mpNum)->getPtr();
    }

    // Get the weapon used (if hand-to-hand, weapon = inv.end())
    if (attack.type == attack.MELEE)
    {
        MWWorld::Ptr weapon;
        MWWorld::Ptr projectile;

        if (attacker.getClass().hasInventoryStore(attacker))
        {
            MWWorld::InventoryStore &inventoryStore = attacker.getClass().getInventoryStore(attacker);
            MWWorld::ContainerStoreIterator weaponSlot = inventoryStore.getSlot(
                MWWorld::InventoryStore::Slot_CarriedRight);
            MWWorld::ContainerStoreIterator projectileSlot = inventoryStore.getSlot(
                MWWorld::InventoryStore::Slot_Ammunition);

            // TODO: Fix for when arrows, bolts and throwing weapons have just run out
            weapon = weaponSlot != inventoryStore.end() ? *weaponSlot : MWWorld::Ptr();
            projectile = projectileSlot != inventoryStore.end() ? *projectileSlot : MWWorld::Ptr();

            if (!weapon.isEmpty() && weapon.getTypeName() != typeid(ESM::Weapon).name())
                weapon = MWWorld::Ptr();
        }

        if (victim.mRef != nullptr)
        {
            bool healthdmg = true;

            if (weapon.isEmpty())
            {
                if (attacker.getClass().isBipedal(attacker))
                {
                    MWMechanics::CreatureStats &otherstats = victim.getClass().getCreatureStats(victim);
                    healthdmg = otherstats.isParalyzed() || otherstats.getKnockedDown();
                }
            }
            else
            {
                LOG_APPEND(Log::LOG_VERBOSE, "- weapon: %s", weapon.getCellRef().getRefId().c_str());

                MWMechanics::blockMeleeAttack(attacker, victim, weapon, attack.damage, 1);

                if (attack.applyWeaponEnchantment)
                {
                    MWMechanics::CastSpell cast(attacker, victim, false);
                    cast.mHitPosition = attack.hitPosition.asVec3();
                    cast.cast(weapon, false);
                }

                if (attack.applyProjectileEnchantment)
                {
                    MWMechanics::CastSpell cast(attacker, victim, false);
                    cast.mHitPosition = attack.hitPosition.asVec3();
                    cast.cast(projectile, false);
                }
            }

            victim.getClass().onHit(victim, attack.damage, healthdmg, weapon, attacker, attack.hitPosition.asVec3(),
                attack.success);
        }
    }
    else if (attack.type == attack.MAGIC)
    {
        attackerStats.getSpells().setSelectedSpell(attack.spellId);

        if (attack.instant)
        {
            MWBase::Environment::get().getWorld()->castSpell(attacker);
            attack.instant = false;
        }

        LOG_APPEND(Log::LOG_VERBOSE, "- spellId: %s, success: %s", attack.spellId.c_str(), attack.success ? "true" : "false");
    }
    else if (attack.type == attack.ITEM_MAGIC)
    {
        attackerStats.getSpells().setSelectedSpell("");

        MWWorld::InventoryStore& inventoryStore = attacker.getClass().getInventoryStore(attacker);

        MWWorld::ContainerStoreIterator it = inventoryStore.begin();
        for (; it != inventoryStore.end(); ++it)
        {
            if (Misc::StringUtils::ciEqual(it->getCellRef().getRefId(), attack.itemId))
                break;
        }

        if (it != inventoryStore.end())
        {
            inventoryStore.setSelectedEnchantItem(it);
            LOG_APPEND(Log::LOG_VERBOSE, "- itemId: %s", attack.itemId.c_str());
            MWBase::Environment::get().getWorld()->castSpell(attacker);
            inventoryStore.setSelectedEnchantItem(inventoryStore.end());
        }
        else
        {
            LOG_MESSAGE_SIMPLE(Log::LOG_ERROR, "Could not find item %s used by %s to cast item spell!",
                attack.itemId.c_str(), attacker.getCellRef().getRefId().c_str());
        }
    }
}

bool MechanicsHelper::doesEffectListContainEffect(const ESM::EffectList& effectList, short effectId, short attributeId, short skillId)
{
    for (const auto &effect : effectList.mList)
    {
        if (effect.mEffectID == effectId)
        {
            if (attributeId == -1 || effect.mAttribute == attributeId)
            {
                if (skillId == -1 || effect.mSkill == skillId)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void MechanicsHelper::unequipItemsByEffect(const MWWorld::Ptr& ptr, short enchantmentType, short effectId, short attributeId, short skillId)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();
    MWWorld::InventoryStore &ptrInventory = ptr.getClass().getInventoryStore(ptr);

    for (int slot = 0; slot < MWWorld::InventoryStore::Slots; slot++)
    {
        if (ptrInventory.getSlot(slot) != ptrInventory.end())
        {
            MWWorld::ConstContainerStoreIterator itemIterator = ptrInventory.getSlot(slot);
            std::string enchantmentName = itemIterator->getClass().getEnchantment(*itemIterator);

            if (!enchantmentName.empty())
            {
                const ESM::Enchantment* enchantment = world->getStore().get<ESM::Enchantment>().find(enchantmentName);

                if (enchantment->mData.mType == enchantmentType && doesEffectListContainEffect(enchantment->mEffects, effectId, attributeId, skillId))
                    ptrInventory.unequipSlot(slot, ptr);
            }
        }
    }
}

MWWorld::Ptr MechanicsHelper::getItemPtrFromStore(const mwmp::Item& item, MWWorld::ContainerStore& store)
{
    for (MWWorld::ContainerStoreIterator storeIterator = store.begin(); storeIterator != store.end(); ++storeIterator)
    {
        if (Misc::StringUtils::ciEqual(item.refId, storeIterator->getCellRef().getRefId()) &&
            item.count == storeIterator->getRefData().getCount() &&
            item.charge == storeIterator->getCellRef().getCharge() &&
            item.enchantmentCharge == storeIterator->getCellRef().getEnchantmentCharge() &&
            Misc::StringUtils::ciEqual(item.soul, storeIterator->getCellRef().getSoul()))
        {
            return *storeIterator;
        }
    }

    return 0;
}
