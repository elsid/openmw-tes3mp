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

        bool isValid;
    };
}

#endif //OPENMW_BASEWORLDSTATE_HPP
