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
    };
}

#endif //OPENMW_PROCESSORSCRIPTMEMBERFLOAT_HPP
