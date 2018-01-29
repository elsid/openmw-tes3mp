#ifndef OPENMW_PROCESSORSCRIPTMEMBERFLOAT_HPP
#define OPENMW_PROCESSORSCRIPTMEMBERFLOAT_HPP

#include "../WorldProcessor.hpp"

namespace mwmp
{
    class ProcessorScriptMemberFloat : public WorldProcessor
    {
    public:
        ProcessorScriptMemberFloat()
        {
            BPP_INIT(ID_SCRIPT_MEMBER_FLOAT)
        }

        virtual void Do(WorldPacket &packet, WorldEvent &event)
        {
            LOG_MESSAGE_SIMPLE(Log::LOG_VERBOSE, "Received %s", strPacketID.c_str());
            //event.setMemberFloats();
        }
    };
}

#endif //OPENMW_PROCESSORSCRIPTMEMBERFLOAT_HPP
