#ifndef OPENMW_PROCESSORSCRIPTLOCALSHORT_HPP
#define OPENMW_PROCESSORSCRIPTLOCALSHORT_HPP

#include "BaseObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorScriptLocalShort : public BaseObjectProcessor
    {
    public:
        ProcessorScriptLocalShort()
        {
            BPP_INIT(ID_SCRIPT_LOCAL_SHORT)
        }

        virtual void Do(ObjectPacket &packet, ObjectList &objectList)
        {
            BaseObjectProcessor::Do(packet, objectList);

            objectList.setLocalShorts(ptrCellStore);
        }
    };
}

#endif //OPENMW_PROCESSORSCRIPTLOCALSHORT_HPP
