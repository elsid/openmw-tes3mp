#ifndef OPENMW_BASEWORLDSTATE_HPP
#define OPENMW_BASEWORLDSTATE_HPP

#include <vector>

#include <components/openmw-mp/Base/BaseStructs.hpp>

#include <RakNetTypes.h>

namespace mwmp
{
    static const int maxImageDataSize = 1800;

    struct MapTile
    {
        int x;
        int y;
        std::vector<char> imageData;
    };

    struct Weather
    {
        std::string region;
        unsigned int currentWeather;
        unsigned int nextWeather;
        unsigned int queuedWeather;
        float transitionFactor;
    };

    class BaseWorldstate
    {
    public:

        BaseWorldstate()
        {
            time.year = -1;
            time.month = -1;
            time.day = -1;
            time.hour = -1;

            time.daysPassed = -1;
            time.timeScale = -1;
        }

        RakNet::RakNetGUID guid;

        mwmp::Time time;

        bool hasPlayerCollision;
        bool hasActorCollision;
        bool hasPlacedObjectCollision;
        bool useActorCollisionForPlacedObjects;

        std::string authorityRegion;

        std::vector<std::string> enforcedCollisionRefIds;

        std::vector<MapTile> mapTiles;

        bool forceWeather;
        Weather weather;

        bool isValid;
    };
}

#endif //OPENMW_BASEWORLDSTATE_HPP
