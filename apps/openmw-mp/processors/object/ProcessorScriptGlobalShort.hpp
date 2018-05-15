#ifndef OPENMW_PROCESSORSCRIPTGLOBALSHORT_HPP
#define OPENMW_PROCESSORSCRIPTGLOBALSHORT_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorScriptGlobalShort : public ObjectProcessor
    {
    public:
        ProcessorScriptGlobalShort()
        {
            BPP_INIT(ID_SCRIPT_GLOBAL_SHORT)
        }
    };
}

#endif //OPENMW_PROCESSORSCRIPTGLOBALSHORT_HPP
