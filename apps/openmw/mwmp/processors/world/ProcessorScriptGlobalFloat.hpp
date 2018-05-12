#ifndef OPENMW_PROCESSORSCRIPTGLOBALFLOAT_HPP
#define OPENMW_PROCESSORSCRIPTGLOBALFLOAT_HPP

#include "../WorldProcessor.hpp"

namespace mwmp
{
    class ProcessorScriptGlobalFloat : public WorldProcessor
    {
    public:
        ProcessorScriptGlobalFloat()
        {
            BPP_INIT(ID_SCRIPT_GLOBAL_FLOAT)
        }

        virtual void Do(ObjectPacket &packet, WorldEvent &event)
        {
            LOG_MESSAGE_SIMPLE(Log::LOG_VERBOSE, "Received %s", strPacketID.c_str());
            //event.setGlobalFloats();
        }
    };
}

#endif //OPENMW_PROCESSORSCRIPTGLOBALFLOAT_HPP
