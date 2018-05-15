#ifndef OPENMW_PROCESSORSCRIPTLOCALSHORT_HPP
#define OPENMW_PROCESSORSCRIPTLOCALSHORT_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorScriptLocalShort : public ObjectProcessor
    {
    public:
        ProcessorScriptLocalShort()
        {
            BPP_INIT(ID_SCRIPT_LOCAL_SHORT)
        }
    };
}

#endif //OPENMW_PROCESSORSCRIPTLOCALSHORT_HPP
