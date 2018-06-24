#ifndef OPENMW_WORLDSTATE_HPP
#define OPENMW_WORLDSTATE_HPP

#include <components/openmw-mp/Base/BaseWorldstate.hpp>

namespace mwmp
{
    class Networking;
    class Worldstate : public BaseWorldstate
    {
    public:

        Worldstate();
        virtual ~Worldstate();

        bool containsExploredMapTile(int cellX, int cellY);

        void markExploredMapTile(int cellX, int cellY);

        void setMapExplored();

        void sendMapExplored(int cellX, int cellY, const std::vector<char>& imageData);

    private:

        std::vector<MapTile> exploredMapTiles;

        Networking *getNetworking();

    };
}

#endif //OPENMW_WORLDSTATE_HPP
