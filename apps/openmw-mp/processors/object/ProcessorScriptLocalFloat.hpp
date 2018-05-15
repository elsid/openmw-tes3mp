#ifndef OPENMW_PROCESSORSCRIPTLOCALFLOAT_HPP
#define OPENMW_PROCESSORSCRIPTLOCALFLOAT_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorScriptLocalFloat : public ObjectProcessor
    {
    public:
        ProcessorScriptLocalFloat()
        {
            BPP_INIT(ID_SCRIPT_LOCAL_FLOAT)
        }
    };
}

#endif //OPENMW_PROCESSORSCRIPTLOCALFLOAT_HPP
