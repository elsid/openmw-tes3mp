#ifndef OPENMW_PROCESSOROBJECTCOLLISION_HPP
#define OPENMW_PROCESSOROBJECTCOLLISION_HPP

#include "BaseObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorObjectCollision : public BaseObjectProcessor
    {
    public:
        ProcessorObjectCollision()
        {
            BPP_INIT(ID_OBJECT_COLLISION)
        }

        virtual void Do(ObjectPacket &packet, ObjectList &objectList)
        {
            BaseObjectProcessor::Do(packet, objectList);

            //objectList.setObjectCollisions(ptrCellStore);
        }

    };
}

#endif //OPENMW_PROCESSOROBJECTCOLLISION_HPP
