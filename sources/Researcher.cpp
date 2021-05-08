#include "Researcher.hpp"

using namespace std;

const int numberOfCardsTreat=5;

namespace pandemic
{
    Researcher::Researcher(Board& b, City c) : Player(b, c) {}

    string Researcher::role() { return "Researcher"; }

    Researcher &Researcher::discover_cure(Color c)
    {
        if (!myBoard.hasCure(c))
        {
            if (myColors.at(c) < numberOfCardsTreat)
            {
                throw invalid_argument("Can't discover: There are not enough cards of this color");
            }

            myColors.at(c) -= numberOfCardsTreat;
            myBoard.disCure(c);
            int count = numberOfCardsTreat;

            auto it = myCards.begin();
            while( it != myCards.end() && count > 0)
            {
                City ci=*it;
                // if (myBoard.colors.at(ci) == c)
                if (myBoard.colors.at(*it) == c)
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