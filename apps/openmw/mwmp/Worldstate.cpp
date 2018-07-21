#include <components/openmw-mp/Log.hpp>

#include "../mwbase/environment.hpp"

#include "../mwgui/windowmanagerimp.hpp"

#include "../mwworld/player.hpp"
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

void Worldstate::setWeather()
{
    MWBase::World *world = MWBase::Environment::get().getWorld();

    // There's a chance we've been sent the weather for a region right after a teleportation
    // that hasn't been registered in the WeatherManager yet, meaning the WeatherManager
    // doesn't have the correct new region set for us, so make sure we update it
    world->updateWeather(0);

    LOG_MESSAGE_SIMPLE(Log::LOG_VERBOSE, "Setting weather for region: %s, currentWeather: %i, "
        "nextWeather: %i, queuedWeather: %i, transitionFactor: %f, forceWeather is %s",
        weather.region.c_str(), weather.currentWeather, weather.nextWeather,
        weather.queuedWeather, weather.transitionFactor, forceWeather ? "true" : "false");

    world->setRegionWeather(weather.region.c_str(), weather.currentWeather, weather.nextWeather,
        weather.queuedWeather, weather.transitionFactor, forceWeather);
}

void Worldstate::sendMapExplored(int cellX, int cellY, const std::vector<char>& imageData)
{
    mapTiles.clear();

    mwmp::MapTile mapTile;
    mapTile.x = cellX;
    mapTile.y = cellY;
    mapTile.imageData = imageData;

    LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Sending ID_PLAYER_MAP with x: %i, y: %i", cellX, cellY);

    mapTiles.push_back(mapTile);

    getNetworking()->getWorldstatePacket(ID_WORLD_MAP)->setWorldstate(this);
    getNetworking()->getWorldstatePacket(ID_WORLD_MAP)->Send();
}

void Worldstate::sendWeather(std::string region, int currentWeather, int nextWeather, int queuedWeather, float transitionFactor)
{
    forceWeather = false;
    weather.region = region;
    weather.currentWeather = currentWeather;
    weather.nextWeather = nextWeather;
    weather.queuedWeather = queuedWeather;
    weather.transitionFactor = transitionFactor;

    LOG_MESSAGE_SIMPLE(Log::LOG_VERBOSE, "Sending ID_PLAYER_WEATHER with region: %s, currentWeather: %i, "
        "nextWeather: %i, queuedWeather, %i, transitionFactor: %f",
        region.c_str(), currentWeather, nextWeather, queuedWeather, transitionFactor);

    getNetworking()->getWorldstatePacket(ID_WORLD_WEATHER)->setWorldstate(this);
    getNetworking()->getWorldstatePacket(ID_WORLD_WEATHER)->Send();
}
