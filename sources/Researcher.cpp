#include "Researcher.hpp"

using namespace std;

const int numberOfCardsDis=5;

namespace pandemic
{
    Researcher::Researcher(Board& b, City c) : Player(b, c) {}

    string Researcher::role() { return "Researcher"; }

    Researcher &Researcher::discover_cure(Color c)
    {
        if (!myBoard.hasCure(c))
        {
            if (myColors.at(c) < numberOfCardsDis)
            {
                throw invalid_argument("Can't discover: There are not enough cards of this color");
            }

            myColors.at(c) -= numberOfCardsDis;
            myBoard.disCure(c);
            int count = numberOfCardsDis;

            auto it = myCards.begin();
            while( it != myCards.end() && count > 0)
            {
                if (Board::colors.at(*it) == c)
                {
                    myCards.erase(it++);
                    count--;
                }
                else
                {
                    ++it;
                }
            }
        }

        return *this;
    }
};