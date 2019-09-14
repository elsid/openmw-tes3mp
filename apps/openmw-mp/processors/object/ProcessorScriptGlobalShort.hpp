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

        void Do(ObjectPacket &packet, Player &player, BaseObjectList &objectList) override
        {
            LOG_MESSAGE_SIMPLE(TimedLog::LOG_INFO, "Received %s from %s", strPacketID.c_str(), player.npc.mName.c_str());

            Script::Call<Script::CallbackIdentity("OnScriptGlobalShort")>(player.getId());
        }
    };
}

#endif //OPENMW_PROCESSORSCRIPTGLOBALSHORT_HPP
