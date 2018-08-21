#include "actiontake.hpp"

/*
    Start of tes3mp addition

    Include additional headers for multiplayer purposes
*/
#include "../mwmp/Main.hpp"
#include "../mwmp/Networking.hpp"
#include "../mwmp/ObjectList.hpp"
#include "../mwmp/LocalPlayer.hpp"
/*
    End of tes3mp addition
*/

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/mechanicsmanager.hpp"

#include "class.hpp"
#include "containerstore.hpp"

namespace MWWorld
{
    ActionTake::ActionTake (const MWWorld::Ptr& object) : Action (true, object) {}

    void ActionTake::executeImp (const Ptr& actor)
    {
        MWBase::Environment::get().getMechanicsManager()->itemTaken(
                    actor, getTarget(), MWWorld::Ptr(), getTarget().getRefData().getCount());
        MWWorld::Ptr newitem = *actor.getClass().getContainerStore (actor).add (getTarget(), getTarget().getRefData().getCount(), actor);

        /*
            Start of tes3mp addition

            Send an ID_OBJECT_DELETE packet every time an item is taken from the world
            by the player outside of the inventory screen

            Send an ID_PLAYER_INVENTORY packet as well with the item thus gained
            by the player
        */
        mwmp::ObjectList *objectList = mwmp::Main::get().getNetworking()->getObjectList();
        objectList->reset();
        objectList->packetOrigin = mwmp::CLIENT_GAMEPLAY;
        objectList->addObjectDelete(getTarget());
        objectList->sendObjectDelete();

        // If the item is gold, make sure we get the correct value
        unsigned int itemCount = getTarget().getClass().isGold(newitem) ? getTarget().getCellRef().getGoldValue() : getTarget().getRefData().getCount();

        mwmp::Main::get().getLocalPlayer()->sendItemChange(getTarget(), itemCount, mwmp::InventoryChanges::ADD);
        /*
            End of tes3mp addition
        */

        MWBase::Environment::get().getWorld()->deleteObject (getTarget());
        setTarget(newitem);
    }
}
