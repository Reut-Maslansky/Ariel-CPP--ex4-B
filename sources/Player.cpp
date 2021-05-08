#include "Player.hpp"
using namespace std;

const int numberOfCardsDis=5;

namespace pandemic
{

    Player::Player(Board &b, City c) : myBoard(b), myLocation(c)
    {
        myColors = {{Color::Yellow, 0}, {Color::Black, 0}, {Color::Red, 0}, {Color::Blue, 0}};
    }

    Player &Player::drive(City c)
    {
        if(myLocation==c){
            throw invalid_argument("Can't drive: This city is current location of the player");
        }
        if (Board::neighbors.at(myLocation).count(c) == 0)
        {
            throw invalid_argument("Can't drive: This city is not a neighbor of the current city");
        }
        myLocation = c;
        return *this;
    }

    Player &Player::fly_direct(City c)
    {
        if(myLocation==c){
            throw invalid_argument("Can't fly: This city is current location of the player");
        }
        if (myCards.count(c) == 0)
        {
            throw invalid_argument("Can't fly: The player does not hold a matching card");
        }
        myCards.erase(c);
        myColors.at(Board::colors.at(c))--;
        myLocation = c;
        return *this;
    }

    Player &Player::fly_charter(City c)
    {
        if(myLocation==c){
            throw invalid_argument("Can't fly: This city is current location of the player");
        }
        if (myCards.count(myLocation) == 0)
        {
            throw invalid_argument("Can't fly: The player does not hold a matching card");
        }
        myCards.erase(myLocation);
        myColors.at(Board::colors.at(myLocation))--;
        myLocation = c;
        return *this;
    }

    Player &Player::fly_shuttle(City c)
    {
        if(myLocation==c){
            throw invalid_argument("Can't fly: This city is current location of the player");
        }
        if (!myBoard.hasStation(myLocation) || !myBoard.hasStation(c))
        {
            throw invalid_argument("Can't fly: This city does not have a research station");
        }
        myLocation = c;
        return *this;
    }

    Player &Player::build()
    {
        if (myCards.count(myLocation) == 0)
        {
            throw invalid_argument("Can't build: The player does not hold a matching card");
        }
        if (!myBoard.hasStation(myLocation))
        {
            myCards.erase(myLocation);
            myColors.at(Board::colors.at(myLocation))--;
            myBoard.buildStation(myLocation);
        }
        return *this;
    }

    Player &Player::discover_cure(Color c)
    {
        if (!myBoard.hasCure(c))
        {
            if (!myBoard.hasStation(myLocation))
            {
                throw invalid_argument("Can't discover: This city does not have a research station");
            }
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

    Player &Player::treat(City c)
    {
        if (myLocation != c)
        {
            throw invalid_argument("Can't treat: This city is not the current city");
        }
        if (myBoard[myLocation] == 0)
        {
            throw invalid_argument("Can't treat: There is no pollution in this city");
        }
        if (myBoard.hasCure(Board::colors.at(c)))
        {
            myBoard[c] = 0;
        }
        else
        {
            myBoard[c]--;
        }
        return *this;
    }
    string Player::role() { return "Player"; }

    Player &Player::take_card(City c)
    {
        myColors.at(Board::colors.at(c))++;
        myCards.insert(c);
        return *this;
    }

    void Player::remove_cards()
    {
        myCards.clear();
    }

};