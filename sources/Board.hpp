#pragma once
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Board
    {
    private:
        std::map<City, int> diseaseLevel;

        std::map<Color, bool> discoverCure;

        std::map<City, bool> researchStation;

    public:
        static std::map<City, Color> colors;

        static std::map<City, std::set<City>> neighbors;

        static std::map<City, std::string> getCity;

        Board();

        bool is_clean();

        int &operator[](City c);

        int operator[](City c) const;

        friend std::ostream &operator<<(std::ostream &, const Board &);

        void remove_cures();

        void remove_stations();

        bool hasCure(Color c);

        void disCure(Color c);

        bool hasStation(City c);
        
        void buildStation(City c);

    };
}