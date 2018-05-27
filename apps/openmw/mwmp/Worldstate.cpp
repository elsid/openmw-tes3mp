#include "Worldstate.hpp"
#include "Main.hpp"
#include "Networking.hpp"

using namespace mwmp;
using namespace std;

Worldstate::Worldstate()
{

}

Worldstate::~Worldstate()
{

}

Networking *Worldstate::getNetworking()
{
    return mwmp::Main::get().getNetworking();
}
