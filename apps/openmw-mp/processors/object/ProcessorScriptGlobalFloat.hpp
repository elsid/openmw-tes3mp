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
    };
}

#endif //OPENMW_PROCESSORSCRIPTGLOBALFLOAT_HPP
