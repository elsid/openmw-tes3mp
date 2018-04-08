#include <components/openmw-mp/Log.hpp>
#include <apps/openmw/mwclass/creature.hpp>

#include "../mwbase/environment.hpp"

#include "../mwclass/npc.hpp"

#include "../mwmechanics/creaturestats.hpp"

#include "../mwworld/cellstore.hpp"
#include "../mwworld/player.hpp"
#include "../mwworld/worldimp.hpp"

#include "PlayerList.hpp"
#include "Main.hpp"
#include "DedicatedPlayer.hpp"
#include "CellController.hpp"
#include "GUIController.hpp"


using namespace mwmp;
using namespace std;

std::map <RakNet::RakNetGUID, DedicatedPlayer *> PlayerList::players;

void PlayerList::update(float dt)
{
    for (auto &p : players)
    {
        DedicatedPlayer *player = p.second;
        if (player == 0) continue;

        player->update(dt);
    }
}

DedicatedPlayer *PlayerList::newPlayer(RakNet::RakNetGUID guid)
{
    LOG_APPEND(Log::LOG_INFO, "- Creating new DedicatedPlayer with guid %s", guid.ToString());

    players[guid] = new DedicatedPlayer(guid);
    players[guid]->state = 0;
    return players[guid];
}

void PlayerList::disconnectPlayer(RakNet::RakNetGUID guid)
{
    if (players[guid]->state > 1)
    {
        players[guid]->state = 1;

        // Remove player's marker
        players[guid]->setMarkerState(false);

        MWBase::World *world = MWBase::Environment::get().getWorld();
        world->disable(players[guid]->getPtr());

        // Move player to exterior 0,0
        ESM::Position newPos;
        newPos.pos[0] = newPos.pos[1] = Main::get().getCellController()->getCellSize() / 2;
        newPos.pos[2] = 0;
        MWWorld::CellStore *cellStore = world->getExterior(0, 0);

        world->moveObject(players[guid]->getPtr(), cellStore, newPos.pos[0], newPos.pos[1], newPos.pos[2]);
    }
}

void PlayerList::cleanUp()
{
    for (auto &p : players)
        delete p.second;
}

DedicatedPlayer *PlayerList::getPlayer(RakNet::RakNetGUID guid)
{
    return players[guid];
}

DedicatedPlayer *PlayerList::getPlayer(const MWWorld::Ptr &ptr)
{
    for (auto &p : players)
    {
        if (p.second == 0 || p.second->getPtr().mRef == 0)
            continue;
        string refid = ptr.getCellRef().getRefId();
        if (p.second->getPtr().getCellRef().getRefId() == refid)
            return p.second;
    }
    return 0;
}

bool PlayerList::isDedicatedPlayer(const MWWorld::Ptr &ptr)
{
    if (ptr.mRef == nullptr)
        return false;

    return (getPlayer(ptr) != 0);
}

/*
    Go through all DedicatedPlayers checking if their mHitAttemptActorId matches this one
    and set it to -1 if it does

    This resets the combat target for a DedicatedPlayer's followers in Actors::update()
*/
void PlayerList::clearHitAttemptActorId(int actorId)
{
    for (auto &p : players)
    {
        if (p.second == 0 || p.second->getPtr().mRef == 0)
            continue;

        MWMechanics::CreatureStats &playerCreatureStats = p.second->getPtr().getClass().getCreatureStats(p.second->getPtr());

        if (playerCreatureStats.getHitAttemptActorId() == actorId)
            playerCreatureStats.setHitAttemptActorId(-1);
    }
}
