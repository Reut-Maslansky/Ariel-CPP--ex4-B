#include "GeneSplicer.hpp"

using namespace std;

const int numberOfCardsDis=5;

namespace pandemic
{
    GeneSplicer::GeneSplicer(Board& b, City c) : Player(b, c) {}
    
    string GeneSplicer::role() { return "GeneSplicer"; }
    
    GeneSplicer &GeneSplicer::discover_cure(Color c)
    {
        if (!myBoard.hasCure(c))
        {
            if (!myBoard.hasStation(myLocation))
            {
                throw invalid_argument("Can't discover: This city does not have a research station");
            }
            if (myCards.size() < numberOfCardsDis)
            {
                throw invalid_argument("Can't discover: There are not enough cards");
            }

            myBoard.disCure(c);
            int count = numberOfCardsDis;

            for (auto it = myCards.begin(); it != myCards.end() && count > 0; ++it)
            {
                myCards.erase(it++);
                myColors.at(Board::colors.at(*it))--;
                count--;
            }
        }
        return *this;
    }
};