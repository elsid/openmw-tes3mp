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

void Worldstate::sendMapExplored(int x, int y, const std::vector<char>& imageData)
{
    mapChanges.mapTiles.clear();

    mwmp::MapTile mapTile;
    mapTile.x = x;
    mapTile.y = y;
    mapTile.imageData = imageData;

    LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Sending ID_PLAYER_MAP with x: %i, y: %i", x, y);

    mapChanges.mapTiles.push_back(mapTile);

    getNetworking()->getWorldstatePacket(ID_WORLD_MAP)->setWorldstate(this);
    getNetworking()->getWorldstatePacket(ID_WORLD_MAP)->Send();
}

void Worldstate::setMapExplored()
{
    for (const auto &mapTile : mapChanges.mapTiles)
    {
        const MWWorld::CellStore *cellStore = MWBase::Environment::get().getWorld()->getExterior(mapTile.x, mapTile.y);

        if (!cellStore->getCell()->mName.empty())
            MWBase::Environment::get().getWindowManager()->addVisitedLocation(cellStore->getCell()->mName, mapTile.x, mapTile.y);

        MWBase::Environment::get().getWindowManager()->setGlobalMapImage(mapTile.x, mapTile.y, mapTile.imageData);
    }
}
