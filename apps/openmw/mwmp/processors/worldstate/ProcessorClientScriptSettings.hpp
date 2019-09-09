#ifndef OPENMW_PROCESSORCLIENTSCRIPTSETTINGS_HPP
#define OPENMW_PROCESSORCLIENTSCRIPTSETTINGS_HPP


#include <apps/openmw/mwbase/world.hpp>
#include <apps/openmw/mwbase/environment.hpp>
#include "../WorldstateProcessor.hpp"

namespace mwmp
{
    class ProcessorClientScriptSettings : public WorldstateProcessor
    {
    public:
        ProcessorClientScriptSettings()
        {
            BPP_INIT(ID_CLIENT_SCRIPT_SETTINGS)
        }

        virtual void Do(WorldstatePacket &packet, Worldstate &worldstate)
        {
            // Placeholder
        }
    };
}



#endif //OPENMW_PROCESSORCLIENTSCRIPTSETTINGS_HPP
