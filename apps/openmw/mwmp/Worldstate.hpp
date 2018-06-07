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

        void setMapExplored();

        void sendMapExplored(int x, int y, const std::vector<char>& imageData);

    private:
        Networking *getNetworking();

    };
}

#endif //OPENMW_WORLDSTATE_HPP
