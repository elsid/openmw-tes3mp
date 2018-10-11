#ifndef OPENMW_PROCESSORPLAYERITEMUSE_HPP
#define OPENMW_PROCESSORPLAYERITEMUSE_HPP

#include "apps/openmw/mwbase/environment.hpp"
#include "apps/openmw/mwgui/inventorywindow.hpp"
#include "apps/openmw/mwgui/windowmanagerimp.hpp"
#include "apps/openmw/mwworld/inventorystore.hpp"

#include "apps/openmw/mwmp/MechanicsHelper.hpp"

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerItemUse : public PlayerProcessor
    {
    public:
        ProcessorPlayerItemUse()
        {
            BPP_INIT(ID_PLAYER_ITEM_USE)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            if (!isLocal()) return;

            LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Received ID_PLAYER_ITEM_USE about LocalPlayer from server");

            if (!isRequest())
            {
                // Due to a bug on Linux w/ vsnprintf, we have to append soul as string here instead
                std::string msgStr = "- refId: %s, count: %i, charge: %f, enchantmentCharge: %f, soul: " + player->usedItem.soul;
                LOG_APPEND(Log::LOG_INFO, msgStr.c_str(),
                    player->usedItem.refId.c_str(), player->usedItem.count, player->usedItem.charge,
                    player->usedItem.enchantmentCharge);


                MWWorld::Ptr playerPtr = MWBase::Environment::get().getWorld()->getPlayerPtr();
                MWWorld::InventoryStore &inventoryStore = playerPtr.getClass().getInventoryStore(playerPtr);

                MWWorld::Ptr itemPtr = MechanicsHelper::getItemPtrFromStore(player->usedItem, inventoryStore);
                MWBase::Environment::get().getWindowManager()->getInventoryWindow()->useItem(itemPtr);
            }
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERITEMUSE_HPP
