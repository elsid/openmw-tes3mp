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
            month = -1;
            day = -1;
            hour = -1;

            daysPassed = -1;
            timeScale = -1;
        }

        RakNet::RakNetGUID guid;

        int month;
        int day;
        double hour;

        int daysPassed;
        float timeScale;

        bool isValid;
    };
}

#endif //OPENMW_BASEWORLDSTATE_HPP
