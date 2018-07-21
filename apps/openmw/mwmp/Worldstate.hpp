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
        void setWeather();

        void sendMapExplored(int cellX, int cellY, const std::vector<char>& imageData);
        void sendWeather(std::string region, int currentWeather, int nextWeather, int queuedWeather, float transitionFactor);

    private:

        std::vector<MapTile> exploredMapTiles;

        Networking *getNetworking();

    };
}

#endif //OPENMW_WORLDSTATE_HPP
