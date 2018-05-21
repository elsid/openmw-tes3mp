#ifndef OPENMW_BASEWORLDSTATE_HPP
#define OPENMW_BASEWORLDSTATE_HPP

#include <components/openmw-mp/Base/BaseStructs.hpp>

#include <RakNetTypes.h>

namespace mwmp
{

    class BaseWorldstate
    {
    public:

        BaseWorldstate()
        {

        }

        RakNet::RakNetGUID guid;

        int month;
        int day;
        double hour;

        bool isValid;
    };
}

#endif //OPENMW_BASEWORLDSTATE_HPP
