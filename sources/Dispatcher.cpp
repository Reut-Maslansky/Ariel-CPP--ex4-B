#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    Dispatcher::Dispatcher(Board& b, City c) : Player(b, c) {}

    string Dispatcher::role() { return "Dispatcher"; }

    Dispatcher &Dispatcher::fly_direct(City c)
    {
         if(myLocation==c){
            throw invalid_argument("Can't fly: This city is current location of the player");

        }
        if (myBoard.hasStation(myLocation))
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