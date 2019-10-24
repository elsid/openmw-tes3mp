#ifndef OPENMW_PROCESSORCONSOLECOMMAND_HPP
#define OPENMW_PROCESSORCONSOLECOMMAND_HPP

#include "BaseObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorConsoleCommand final: public BaseObjectProcessor
    {
    public:
        ProcessorConsoleCommand()
        {
            BPP_INIT(ID_CONSOLE_COMMAND)
        }

        virtual void Do(ObjectPacket &packet, ObjectList &objectList)
        {
            BaseObjectProcessor::Do(packet, objectList);

            objectList.runConsoleCommands(ptrCellStore);
        }
    };
}

#endif //OPENMW_PROCESSORCONSOLECOMMAND_HPP
