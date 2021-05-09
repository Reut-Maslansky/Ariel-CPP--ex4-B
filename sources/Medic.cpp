#include "Medic.hpp"

using namespace std;

namespace pandemic
{
    Medic::Medic(Board &b, City c) : Player(b, c)
    {
        if (myBoard.hasCure(Board::colors.at(c)))
        {
            myBoard[c] = 0;
        }
    }
    string Medic::role() { return "Medic"; }

    Medic &Medic::drive(City c)
    {
        if (myLocation == c)
        {
            throw invalid_argument("Can't drive: This city is current location of the player");
        }
        if (Board::neighbors.at(myLocation).count(c) == 0)
        {
            throw invalid_argument("Can't drive: This city is not a neighbor of the current city");
        }
        myLocation = c;
        if (myBoard.hasCure(Board::colors.at(c)))
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_direct(City c)
    {
        if (myLocation == c)
        {
            throw invalid_argument("Can't fly: This city is current location of the player");
        }
        if (myCards.count(c) == 0)
        {
            throw invalid_argument("Can't fly: The player does not hold a matching card");
        }
        myCards.erase(c);
        myColors.at(Board::colors.at(c))--;
        myLocation = c;
        if (myBoard.hasCure(Board::colors.at(c)))
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_charter(City c)
    {
        if (myLocation == c)
        {
            throw invalid_argument("Can't fly: This city is current location of the player");
        }
        if (myCards.count(myLocation) == 0)
        {
            throw invalid_argument("Can't fly: The player does not hold a matching card");
        }
        myCards.erase(myLocation);
        myColors.at(Board::colors.at(myLocation))--;
        myLocation = c;

        if (myBoard.hasCure(Board::colors.at(c)))
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_shuttle(City c)
    {
        if (myLocation == c)
        {
            throw invalid_argument("Can't fly: This city is current location of the player");
        }
        if (!myBoard.hasStation(myLocation) || !myBoard.hasStation(c))
        {
            throw invalid_argument("Can't fly: This city does not have a research station");
        }

        myLocation = c;

        if (myBoard.hasCure(Board::colors.at(c)))
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::treat(City c)
    {
        if (myBoard[myLocation] == 0)
        {
            throw invalid_argument("Can't treat: There is no pollution in this city");
        }
        myBoard[myLocation] = 0;
        return *this;
    }
};