#ifndef OPENMW_RECORDHELPER_HPP
#define OPENMW_RECORDHELPER_HPP

#include <components/esm/loadcrea.hpp>
#include <components/esm/loadnpc.hpp>

namespace RecordHelper
{
    bool doesCreatureExist(const std::string& refId);

    std::string createCreatureRecord(const ESM::Creature& creature);
    std::string createNpcRecord(const ESM::NPC& npc);

    void updateCreatureRecord(const ESM::Creature& creature);
    void updateNpcRecord(const ESM::NPC& npc);
}


#endif //OPENMW_RECORDHELPER_HPP
