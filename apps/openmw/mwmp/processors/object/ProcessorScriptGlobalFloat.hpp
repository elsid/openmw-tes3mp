#ifndef OPENMW_PROCESSORSCRIPTGLOBALFLOAT_HPP
#define OPENMW_PROCESSORSCRIPTGLOBALFLOAT_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorScriptGlobalFloat : public ObjectProcessor
    {
    public:
        ProcessorScriptGlobalFloat()
        {
            BPP_INIT(ID_SCRIPT_GLOBAL_FLOAT)
        }

        virtual void Do(ObjectPacket &packet, ObjectList &objectList)
        {
            LOG_MESSAGE_SIMPLE(Log::LOG_VERBOSE, "Received %s", strPacketID.c_str());
            //objectList.setGlobalFloats();
        }
    };
}

#endif //OPENMW_PROCESSORSCRIPTGLOBALFLOAT_HPP
