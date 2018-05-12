#ifndef OPENMW_PROCESSORCONSOLECOMMAND_HPP
#define OPENMW_PROCESSORCONSOLECOMMAND_HPP

#include "BaseObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorConsoleCommand : public BaseObjectProcessor
    {
    public:
        ProcessorConsoleCommand()
        {
            BPP_INIT(ID_CONSOLE_COMMAND)
        }

        virtual void Do(ObjectPacket &packet, WorldEvent &event)
        {
            BaseObjectProcessor::Do(packet, event);

            event.runConsoleCommands(ptrCellStore);
        }
    };
}

#endif //OPENMW_PROCESSORCONSOLECOMMAND_HPP
