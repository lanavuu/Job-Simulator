#include "SuperPoke.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <unordered_map>

pokeBowl::pokeBowl() { // pokebowl is a member of the pokebowl class, compile knows where all the private members come from
    base_ = "";
    topping_ = "";
    protein_ = "";
    sauce_ = "";
    top_off_ = "";
}

void pokeBowl::pickSize() {
    //do rng not user input ur th cashier
    
}

    

void pokePath() { //PATHWAY
    std::unordered_map<std::string, double> pokeMenu;

    pokeMenu["1. Small (2 scoop)"] = 14;
    pokeMenu["2. Medium (3 scoop)"] = 17;
    pokeMenu["3. Large (5 scoop)"] = 22;
    
    std::cout << "Pick your size: ";
    for (auto i : pokeMenu) {
        std::cout << i.first << " $" << i.second; // choosing poke size
    }



}