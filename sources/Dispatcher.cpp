#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    Dispatcher::Dispatcher(Board &b, City c) : Player(b, c) {}

    string Dispatcher::role() { return "Dispatcher"; }

    Dispatcher &Dispatcher::fly_direct(City c)
    {
        if (myBoard.hasStation(myLocation) && myLocation != c)
        {
            myLocation = c;
        }
        else
        {
            Player::fly_direct(c);
        }
        return *this;
    }
};