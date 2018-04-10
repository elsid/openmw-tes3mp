#include <boost/algorithm/clamp.hpp>
#include <components/openmw-mp/Log.hpp>
#include <apps/openmw/mwmechanics/steering.hpp>

#include "../mwbase/environment.hpp"
#include "../mwbase/soundmanager.hpp"

#include "../mwclass/npc.hpp"

#include "../mwdialogue/dialoguemanagerimp.hpp"

#include "../mwgui/windowmanagerimp.hpp"

#include "../mwinput/inputmanagerimp.hpp"

#include "../mwmechanics/actor.hpp"
#include "../mwmechanics/aitravel.hpp"
#include "../mwmechanics/creaturestats.hpp"
#include "../mwmechanics/npcstats.hpp"
#include "../mwmechanics/mechanicsmanagerimp.hpp"
#include "../mwmechanics/spellcasting.hpp"

#include "../mwstate/statemanagerimp.hpp"

#include "../mwworld/action.hpp"
#include "../mwworld/cellstore.hpp"
#include "../mwworld/customdata.hpp"
#include "../mwworld/inventorystore.hpp"
#include "../mwworld/player.hpp"
#include "../mwworld/worldimp.hpp"

#include "DedicatedPlayer.hpp"
#include "Main.hpp"
#include "GUIController.hpp"
#include "CellController.hpp"
#include "MechanicsHelper.hpp"


using namespace mwmp;
using namespace std;

DedicatedPlayer::DedicatedPlayer(RakNet::RakNetGUID guid) : BasePlayer(guid)
{
    reference = 0;
    attack.pressed = 0;

    creatureStats.mDead = false;
    // Give this new character a temporary high fatigue so it doesn't spawn on
    // the ground
    creatureStats.mDynamic[2].mBase = 1000;

    movementFlags = 0;
    attack.instant = false;

    cell.blank();
    position.pos[0] = position.pos[1] = Main::get().getCellController()->getCellSize() / 2;
    position.pos[2] = 0;
}
DedicatedPlayer::~DedicatedPlayer()
{

}

void DedicatedPlayer::update(float dt)
{
    MWMechanics::CreatureStats *ptrCreatureStats = &ptr.getClass().getCreatureStats(ptr);

    MWMechanics::DynamicStat<float> value;

    if (creatureStats.mDead)
    {
        value.readState(creatureStats.mDynamic[0]);
        ptrCreatureStats->setHealth(value);
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        value.readState(creatureStats.mDynamic[i]);
        ptrCreatureStats->setDynamic(i, value);
    }

    if (ptrCreatureStats->isDead())
        ptrCreatureStats->resurrect();

    ptrCreatureStats->setAttacked(false);

    ptrCreatureStats->getAiSequence().stopCombat();

    ptrCreatureStats->setAlarmed(false);
    ptrCreatureStats->setAiSetting(MWMechanics::CreatureStats::AI_Alarm, 0);
    ptrCreatureStats->setAiSetting(MWMechanics::CreatureStats::AI_Fight, 0);
    ptrCreatureStats->setAiSetting(MWMechanics::CreatureStats::AI_Flee, 0);
    ptrCreatureStats->setAiSetting(MWMechanics::CreatureStats::AI_Hello, 0);

    // Only move and set anim flags if the framerate isn't too low
    if (dt < 0.1)
    {
        move(dt);
        setAnimFlags();
    }
}

void DedicatedPlayer::move(float dt)
{
    if (!reference) return;

    ESM::Position refPos = ptr.getRefData().getPosition();
    MWBase::World *world = MWBase::Environment::get().getWorld();
    const int maxInterpolationDistance = 40;

    // Apply interpolation only if the position hasn't changed too much from last time
    bool shouldInterpolate =
            abs(position.pos[0] - refPos.pos[0]) < maxInterpolationDistance &&
            abs(position.pos[1] - refPos.pos[1]) < maxInterpolationDistance &&
            abs(position.pos[2] - refPos.pos[2]) < maxInterpolationDistance;

    if (shouldInterpolate)
    {
        static const int timeMultiplier = 15;
        osg::Vec3f lerp = MechanicsHelper::getLinearInterpolation(refPos.asVec3(), position.asVec3(), dt * timeMultiplier);

        world->moveObject(ptr, lerp.x(), lerp.y(), lerp.z());
    }
    else
        world->moveObject(ptr, position.pos[0], position.pos[1], position.pos[2]);

    float oldZ = ptr.getRefData().getPosition().rot[2];
    world->rotateObject(ptr, position.rot[0], 0, oldZ);

    MWMechanics::Movement *move = &ptr.getClass().getMovementSettings(ptr);
    move->mPosition[0] = direction.pos[0];
    move->mPosition[1] = direction.pos[1];

    MWMechanics::zTurn(ptr, position.rot[2], osg::DegreesToRadians(1.0));
}

void DedicatedPlayer::setBaseInfo()
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    if (reference)
    {
        deleteReference();
    }

    std::string recId = getNpcRecordId();
    createReference(recId);

    setEquipment();
}

void DedicatedPlayer::setShapeshift()
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    if (reference)
    {
        deleteReference();
    }

    std::string recId;

    if (!creatureRefId.empty())
    {
        const ESM::Creature *tmpCreature = world->getStore().get<ESM::Creature>().search(creatureRefId);
        if (tmpCreature != 0)
        {
            recId = getCreatureRecordId();
        }
    }

    if (recId.empty())
    {
        recId = getNpcRecordId();
    }

    createReference(recId);

    if (ptr.getTypeName() == typeid(ESM::NPC).name())
    {
        MWBase::Environment::get().getMechanicsManager()->setWerewolf(ptr, isWerewolf);

        if (!isWerewolf)
            setEquipment();
    }
    
    MWBase::Environment::get().getWorld()->scaleObject(ptr, scale);
}

void DedicatedPlayer::setAnimFlags()
{
    using namespace MWMechanics;

    MWBase::World *world = MWBase::Environment::get().getWorld();

    // Until we figure out a better workaround for disabling player gravity,
    // simply cast Levitate over and over on a player that's supposed to be flying
    if (!isFlying)
        ptr.getClass().getCreatureStats(ptr).getActiveSpells().purgeEffect(ESM::MagicEffect::Levitate);
    else if (isFlying && !world->isFlying(ptr))
    {
        MWMechanics::CastSpell cast(ptr, ptr);
        cast.mHitPosition = ptr.getRefData().getPosition().asVec3();
        cast.mAlwaysSucceed = true;
        cast.cast("Levitate");
    }

    if (drawState == 0)
        ptr.getClass().getCreatureStats(ptr).setDrawState(DrawState_Nothing);
    else if (drawState == 1)
        ptr.getClass().getCreatureStats(ptr).setDrawState(DrawState_Weapon);
    else if (drawState == 2)
        ptr.getClass().getCreatureStats(ptr).setDrawState(DrawState_Spell);

    MWMechanics::CreatureStats *ptrCreatureStats = &ptr.getClass().getCreatureStats(ptr);
    ptrCreatureStats->setMovementFlag(CreatureStats::Flag_Run, (movementFlags & CreatureStats::Flag_Run) != 0);
    ptrCreatureStats->setMovementFlag(CreatureStats::Flag_Sneak, (movementFlags & CreatureStats::Flag_Sneak) != 0);
    ptrCreatureStats->setMovementFlag(CreatureStats::Flag_ForceJump, (movementFlags & CreatureStats::Flag_ForceJump) != 0);
    ptrCreatureStats->setMovementFlag(CreatureStats::Flag_ForceMoveJump, (movementFlags & CreatureStats::Flag_ForceMoveJump) != 0);
}

void DedicatedPlayer::setEquipment()
{
    MWWorld::InventoryStore& invStore = ptr.getClass().getInventoryStore(ptr);
    for (int slot = 0; slot < MWWorld::InventoryStore::Slots; ++slot)
    {
        MWWorld::ContainerStoreIterator it = invStore.getSlot(slot);

        const string &dedicItem = equipedItems[slot].refId;
        std::string item = "";
        bool equal = false;
        if (it != invStore.end())
        {
            item = it->getCellRef().getRefId();
            if (!Misc::StringUtils::ciEqual(item, dedicItem)) // if other item equiped
            {
                MWWorld::ContainerStore &store = ptr.getClass().getContainerStore(ptr);
                store.remove(item, store.count(item), ptr);
            }
            else
                equal = true;
        }

        if (dedicItem.empty() || equal)
            continue;

        const int count = equipedItems[slot].count;
        ptr.getClass().getContainerStore(ptr).add(dedicItem, count, ptr);

        for (const auto &ptr : invStore)
        {
            if (::Misc::StringUtils::ciEqual(ptr.getCellRef().getRefId(), dedicItem)) // equip item
            {
                std::shared_ptr<MWWorld::Action> action = ptr.getClass().use(ptr);
                action->execute(this->ptr);
                break;
            }
        }
    }
}

void DedicatedPlayer::setCell()
{
    // Prevent cell update when reference doesn't exist
    if (!reference) return;

    MWBase::World *world = MWBase::Environment::get().getWorld();

    LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Server says DedicatedPlayer %s moved to %s",
        npc.mName.c_str(), cell.getDescription().c_str());

    MWWorld::CellStore *cellStore = Main::get().getCellController()->getCellStore(cell);

    if (!cellStore)
    {
        LOG_APPEND(Log::LOG_INFO, "%s", "- Cell doesn't exist on this client");
        world->disable(getPtr());
        return;
    }
    else
        world->enable(getPtr());

    // Allow this player's reference to move across a cell now that a manual cell
    // update has been called
    setPtr(world->moveObject(ptr, cellStore, position.pos[0], position.pos[1], position.pos[2]));

    // Remove the marker entirely if this player has moved to an interior that is inactive for us
    if (!cell.isExterior() && !Main::get().getCellController()->isActiveWorldCell(cell))
        removeMarker();
    // Otherwise, update their marker so the player shows up in the right cell on the world map
    else
        updateMarker();

    // If this player is now in a cell that we are the local authority over, we should send them all
    // NPC data in that cell
    if (Main::get().getCellController()->hasLocalAuthority(cell))
        Main::get().getCellController()->getCell(cell)->updateLocal(true);
}

void DedicatedPlayer::updateMarker()
{
    if (!markerEnabled)
        return;

    GUIController *gui = Main::get().getGUIController();

    if (gui->mPlayerMarkers.contains(marker))
    {
        gui->mPlayerMarkers.deleteMarker(marker);
        marker = gui->createMarker(guid);
        gui->mPlayerMarkers.addMarker(marker);
    }
    else
        gui->mPlayerMarkers.addMarker(marker, true);
}

void DedicatedPlayer::removeMarker()
{
    if (!markerEnabled)
        return;

    markerEnabled = false;
    GUIController *gui = Main::get().getGUIController();

    if (gui->mPlayerMarkers.contains(marker))
        Main::get().getGUIController()->mPlayerMarkers.deleteMarker(marker);
}

void DedicatedPlayer::setMarkerState(bool state)
{
    if (state)
    {
        markerEnabled = true;
        updateMarker();
    }
    else
        removeMarker();
}

void DedicatedPlayer::playAnimation()
{
    MWBase::Environment::get().getMechanicsManager()->playAnimationGroup(getPtr(),
        animation.groupname, animation.mode, animation.count, animation.persist);
}

void DedicatedPlayer::playSpeech()
{
    MWBase::Environment::get().getSoundManager()->say(getPtr(), sound);

    MWBase::WindowManager *winMgr = MWBase::Environment::get().getWindowManager();
    if (winMgr->getSubtitlesEnabled())
        winMgr->messageBox(MWBase::Environment::get().getDialogueManager()->getVoiceCaption(sound), MWGui::ShowInDialogueMode_Never);
}

std::string DedicatedPlayer::getNpcRecordId()
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    MWWorld::Ptr player = world->getPlayerPtr();

    ESM::NPC newNpc = *player.get<ESM::NPC>()->mBase;

    // To avoid freezes caused by invalid races, only set race if we find it
    // on our client
    if (world->getStore().get<ESM::Race>().search(npc.mRace) != 0)
        newNpc.mRace = npc.mRace;

    newNpc.mHead = npc.mHead;
    newNpc.mHair = npc.mHair;
    newNpc.mClass = npc.mClass;
    newNpc.mName = npc.mName;
    newNpc.mFlags = npc.mFlags;

    LOG_APPEND(Log::LOG_INFO, "- Creating new NPC record");
    newNpc.mId = "Dedicated Player";
    std::string recId = world->createRecord(newNpc)->mId;

    return recId;
}

std::string DedicatedPlayer::getCreatureRecordId()
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    ESM::Creature creature;

    const ESM::Creature *tmpCreature = world->getStore().get<ESM::Creature>().search(creatureRefId);

    creature = *tmpCreature;
    creature.mScript = "";
    if (!displayCreatureName)
        creature.mName = npc.mName;
    LOG_APPEND(Log::LOG_INFO, "Player %s looks like %s", npc.mName.c_str(), creatureRefId.c_str());

    LOG_APPEND(Log::LOG_INFO, "- Creating new NPC record");
    creature.mId = "Dedicated Player";

    std::string recId = world->createRecord(creature)->mId;

    return recId;
}

void DedicatedPlayer::createReference(const std::string& recId)
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    reference = new MWWorld::ManualRef(world->getStore(), recId, 1);

    LOG_APPEND(Log::LOG_INFO, "- Creating new reference pointer for %s", npc.mName.c_str());

    ptr = world->placeObject(reference->getPtr(), Main::get().getCellController()->getCellStore(cell), position);

    ESM::CustomMarker mEditingMarker = Main::get().getGUIController()->createMarker(guid);
    marker = mEditingMarker;
    setMarkerState(true);
}

void DedicatedPlayer::deleteReference()
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    LOG_APPEND(Log::LOG_INFO, "- Deleting reference");
    world->deleteObject(ptr);
    delete reference;
    reference = nullptr;
}

MWWorld::Ptr DedicatedPlayer::getPtr()
{
    return ptr;
}

MWWorld::ManualRef *DedicatedPlayer::getRef()
{
    return reference;
}

void DedicatedPlayer::setPtr(const MWWorld::Ptr& newPtr)
{
    ptr = newPtr;
}
