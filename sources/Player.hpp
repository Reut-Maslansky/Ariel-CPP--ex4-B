#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Player
    {
    protected:
        Board &myBoard;
        City myLocation;
        std::set<City> myCards;
        std::map<Color,int> myColors;

    public:
        Player(Board &, City);
        virtual Player &drive(City);
        virtual Player &fly_direct(City);
        virtual Player &fly_charter(City);
        virtual Player &fly_shuttle(City);
        virtual Player &build();
        virtual Player &discover_cure(Color);
        virtual Player &treat(City);
        virtual std::string role()=0;
        Player &take_card(City);
        void remove_cards();
    };
}