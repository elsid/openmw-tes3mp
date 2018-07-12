#include <components/openmw-mp/Log.hpp>

#include "../mwbase/environment.hpp"

#include "../mwgui/windowmanagerimp.hpp"

#include "../mwworld/worldimp.hpp"

#include "Worldstate.hpp"
#include "Main.hpp"
#include "Networking.hpp"

using namespace mwmp;
using namespace std;

Worldstate::Worldstate()
{
    hasPlayerCollision = true;
    hasActorCollision = true;
    hasPlacedObjectCollision = false;
    useActorCollisionForPlacedObjects = false;
}

Worldstate::~Worldstate()
{

}

Networking *Worldstate::getNetworking()
{
    return mwmp::Main::get().getNetworking();
}

bool Worldstate::containsExploredMapTile(int cellX, int cellY)
{
    for (const auto &mapTile : exploredMapTiles)
    {
        if (mapTile.x == cellX && mapTile.y == cellY)
            return true;
    }

    return false;
}

void Worldstate::markExploredMapTile(int cellX, int cellY)
{
    mwmp::MapTile exploredTile;
    exploredTile.x = cellX;
    exploredTile.y = cellY;
    exploredMapTiles.push_back(exploredTile);
}

void Worldstate::sendMapExplored(int cellX, int cellY, const std::vector<char>& imageData)
{
    mapTiles.clear();

    mwmp::MapTile mapTile;
    mapTile.x = cellX;
    mapTile.y = cellY;
    mapTile.imageData = imageData;

    LOG_MESSAGE_SIMPLE(Log::LOG_ERROR, "Sending ID_PLAYER_MAP with x: %i, y: %i", cellX, cellY);

    mapTiles.push_back(mapTile);

    getNetworking()->getWorldstatePacket(ID_WORLD_MAP)->setWorldstate(this);
    getNetworking()->getWorldstatePacket(ID_WORLD_MAP)->Send();
}

void Worldstate::setMapExplored()
{
    for (const auto &mapTile : mapTiles)
    {
        const MWWorld::CellStore *cellStore = MWBase::Environment::get().getWorld()->getExterior(mapTile.x, mapTile.y);

        if (!cellStore->getCell()->mName.empty())
            MWBase::Environment::get().getWindowManager()->addVisitedLocation(cellStore->getCell()->mName, mapTile.x, mapTile.y);

        MWBase::Environment::get().getWindowManager()->setGlobalMapImage(mapTile.x, mapTile.y, mapTile.imageData);

        // Keep this tile marked as explored so we don't send any more packets for it
        markExploredMapTile(mapTile.x, mapTile.y);
    }
}
