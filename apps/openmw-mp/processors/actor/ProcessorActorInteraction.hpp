#ifndef OPENMW_PROCESSORACTORINTERACTION_HPP
#define OPENMW_PROCESSORACTORINTERACTION_HPP

#include "../ActorProcessor.hpp"

namespace mwmp
{
    class ProcessorActorInteraction : public ActorProcessor
    {
    public:
        ProcessorActorInteraction()
        {
            BPP_INIT(ID_ACTOR_INTERACTION)
        }

        void Do(ActorPacket &packet, Player &player, BaseActorList &actorList) override
        {
            // Send only to players who have the cell loaded
            Cell *serverCell = CellController::get()->getCell(&actorList.cell);

            if (serverCell != nullptr && *serverCell->getAuthority() == actorList.guid)
                serverCell->sendToLoaded(&packet, &actorList);
        }
    };
}

#endif //OPENMW_PROCESSORACTORINTERACTION_HPP
