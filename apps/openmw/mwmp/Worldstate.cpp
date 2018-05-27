#include "Worldstate.hpp"
#include "Main.hpp"
#include "Networking.hpp"

using namespace mwmp;
using namespace std;

Worldstate::Worldstate()
{
    hasPlayerCollision = true;
    hasActorCollision = true;
    hasPlacedObjectCollision = false;
    useActorCollisionForPlacedObjects = false;
}

Worldstate::~Worldstate()
{

}

Networking *Worldstate::getNetworking()
{
    return mwmp::Main::get().getNetworking();
}
