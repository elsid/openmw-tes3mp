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

    struct MapChanges
    {
        std::vector<MapTile> mapTiles;
    };

    class BaseWorldstate
    {
    public:

        BaseWorldstate()
        {
            month = -1;
            day = -1;
            hour = -1;

            daysPassed = -1;
            timeScale = -1;
        }

        RakNet::RakNetGUID guid;

        double hour;
        int day;
        int month;
        int year;

        int daysPassed;
        float timeScale;

        bool hasPlayerCollision;
        bool hasActorCollision;
        bool hasPlacedObjectCollision;
        bool useActorCollisionForPlacedObjects;

        MapChanges mapChanges;

        bool isValid;
    };
}

#endif //OPENMW_BASEWORLDSTATE_HPP
