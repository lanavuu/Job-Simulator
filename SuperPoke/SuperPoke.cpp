#include "SuperPoke.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <unordered_map>

pokeBowl::pokeBowl() { // pokebowl is a member of the pokebowl class, compile knows where all the private members come from
    base_ = "";
    topping_[5] = "";
    protein_ = "";
    sauce_ = "";
    top_off_ = "";
}

void pokeBowl::pickSize() { //setting size_ to random size
    //do rng not user input ur th cashier
    std::vector<std::string> sizes = {"Small", "Medium", "Large"}; //container of options
    size_ = sizes[rand() % 3]; // random choice, store it into priv var
}

void pokeBowl::pickBase() {
    std::vector<std::string> bases = {"white rice", "brown rice", "salad"};
    base_ = bases[rand() % 3];
}

void pokeBowl::pickTopping() {
    std::vector<std::string> toppings = {"crabmeat", "spicy crabmeat", "seaweed salad", "cucumber", "edamame", "corn",
    "onions", "mango", "pickled radish", "avacado"};
    //how do i store up to five toppings? -> turn into a list
    
    topping_[5] = toppings[rand() % 10];
    //only can select one of each topping, duplicates will cost extra depending on the topping

}

void pokeBowl::pickProteins() {
    int proteinMax;
    std::vector<std::string> proteins = {"salmon", "spicy salmon", "tuna", "spicy tuna", "octopus", "shrimp",
    "scallop", "yellowtail"};
    //if small
    // max 2
    //if medium
    // max 3
    //if large
    // max 5
    if (size_ == "Small") {
        int proteinMax = 2;
    } else if (size_ == "Medium") {
        int proteinMax = 3;
    } else if (size_ == "Large") {
        int proteinMax = 5;
    }
    // randomly choose proteins
    // if random reaches max protein, stop
    // store random proteins in a list
    for (int i = 0; i <= proteinMax; i++) {
        proteins_[proteinMax] = proteins[rand() % 8]; // i randomly selects from proteins vector and keeps storing proteins 
                                                    // until it reaches the max proteins

    }

   
}

void pokeBowl::pickSauce() {

}

std::string pokeBowl::printOrder() {
    std::cout << "You ordered a " ;
}

int pokeBowl::calculateOrder() {

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