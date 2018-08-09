#ifndef OPENMW_PROCESSORPLAYERITEMUSE_HPP
#define OPENMW_PROCESSORPLAYERITEMUSE_HPP

#include "apps/openmw/mwbase/environment.hpp"
#include "apps/openmw/mwgui/inventorywindow.hpp"
#include "apps/openmw/mwgui/windowmanagerimp.hpp"
#include "apps/openmw/mwworld/inventorystore.hpp"

#include "../MechanicsHelper.hpp"
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
                LOG_APPEND(Log::LOG_INFO, "- refId: %s, count: %i, charge: %f, enchantmentCharge: %f, soul: %s",
                    player->usedItem.refId.c_str(), player->usedItem.count, player->usedItem.charge,
                    player->usedItem.enchantmentCharge, player->usedItem.soul.c_str());

                MWWorld::Ptr &playerPtr = MWBase::Environment::get().getWorld()->getPlayerPtr();
                MWWorld::InventoryStore &inventoryStore = playerPtr.getClass().getInventoryStore(playerPtr);

                MWWorld::Ptr &itemPtr = MechanicsHelper::getItemPtrFromStore(player->usedItem, inventoryStore);
                MWBase::Environment::get().getWindowManager()->getInventoryWindow()->useItem(itemPtr);
            }
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERITEMUSE_HPP
