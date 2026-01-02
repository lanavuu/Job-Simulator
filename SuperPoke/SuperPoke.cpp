#include "SuperPoke.hpp"
#include <iostream>
#include <vector>

#include <unordered_map>

void pokePath() {
    std::unordered_map<std::string, double> pokeMenu;

    pokeMenu["1. Small (2 scoop)"] = 14;
    pokeMenu["2. Medium (3 scoop)"] = 17;
    pokeMenu["3. Large (5 scoop)"] = 22;
    
    std::cout << "Pick your size: ";
    for (auto i : pokeMenu) {
        std::cout << i.first << " $" << i.second; // choosing poke size
    }



}