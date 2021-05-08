#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    Virologist::Virologist(Board &b, City c) : Player(b, c) {}

    string Virologist::role() { return "Virologist"; }

    Virologist &Virologist::treat(City c)
    {
        if (c == myLocation)
        {
            Player::treat(c);
        }
        else
        {
            if (myCards.count(c) == 0)
            {
                throw invalid_argument("Can't treat: The player does not hold a matching card");
            }
            if (myBoard.hasCure(Board::colors.at(c)))
            {
                myBoard[c] = 0;
            }
            else
            {
                myBoard[c]--;
            }
            myCards.erase(c);
            myColors.at(Board::colors.at(c))--;
        }
        return *this;
    }
};