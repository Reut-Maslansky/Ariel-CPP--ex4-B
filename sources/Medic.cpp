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
        Player::drive(c);
        if (myBoard.hasCure(Board::colors.at(c)))
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_direct(City c)
    {
        Player::fly_direct(c);

        if (myBoard.hasCure(Board::colors.at(c)))
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_charter(City c)
    {
        Player::fly_charter(c);

        if (myBoard.hasCure(Board::colors.at(c)))
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_shuttle(City c)
    {
        Player::fly_shuttle(c);

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