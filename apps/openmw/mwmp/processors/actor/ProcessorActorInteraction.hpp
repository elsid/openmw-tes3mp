#ifndef OPENMW_PROCESSORACTORINTERACTION_HPP
#define OPENMW_PROCESSORACTORINTERACTION_HPP

#include "../ActorProcessor.hpp"
#include "apps/openmw/mwmp/Main.hpp"
#include "apps/openmw/mwmp/CellController.hpp"

namespace mwmp
{
    class ProcessorActorInteraction : public ActorProcessor
    {
    public:
        ProcessorActorInteraction()
        {
            BPP_INIT(ID_ACTOR_INTERACTION);
        }

        virtual void Do(ActorPacket &packet, ActorList &actorList)
        {
            //Main::get().getCellController()->readInteraction(actorList);
        }
    };
}

#endif //OPENMW_PROCESSORACTORINTERACTION_HPP
