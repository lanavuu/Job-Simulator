#include "SuperPoke.hpp"
#include "../Register/Register.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


#include <unordered_map>

pokeBowl::pokeBowl() { // pokebowl is a member of the pokebowl class, compile knows where all the private members come from
    size_ = "";
    base_ = "no base";
    topping_; //empty vectors
    proteins_;
    sauce_;
    top_off_;
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
    int toppingMax;
    std::vector<std::string> toppings = {"crabmeat", "spicy crabmeat", "seaweed salad", "cucumber", "edamame", "corn",
    "onions", "mango", "pickled radish", "avacado"};
    //how do i store up to five toppings? -> turn into a list
    // randomly choose max amount of topping
    toppingMax = rand() % 5; // randomly choose amount of toppings 1-5
    // store random toppings into topping_ (toppingMax) amount of times
    for (int index = 0; index < toppingMax; index++) {
        topping_[index] = toppings[rand() % 10]; 
        //for current index at topping
        // set it equal to toppings at this random index (random topping)
        // continue until index is less than toppingMax
    }
    

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
        proteinMax = 2;
    } else if (size_ == "Medium") {
        proteinMax = 3;
    } else if (size_ == "Large") {
        proteinMax = 5;
    }
    // randomly choose proteins
    // if random reaches max protein, stop
    // store random proteins in a list
    for (int index = 0; index < proteinMax; index++) {
        proteins_[index] = proteins[rand() % 8]; // i randomly selects from proteins vector and keeps storing proteins 
                                                    // until it reaches the max proteins
    } // index in protein i randomly stores from protein vector while for loop conditrion tru

}

void pokeBowl::pickSauce() { // up to 3 sauzes max
    int sauceMax;
    std::vector<std::string> sauces {"soy sauce", "super sauce", "ponzu", "spicy mayo", "eel sauce", "spizy ponzu"};

    sauceMax = rand() % 3;
    for (int index = 0; index < sauceMax; index++) {
        sauce_[index] = sauces[rand() % 6];
    }

}

std::string pokeBowl::printOrder() {
    std::string toppings;
    std::string proteins;
    std::string sauces;
    std::string topOffs;
    //convert vector to a string ez

    for (int index = 1; index < topping_.size(); index++) {
        toppings = topping_[0];
        toppings = toppings + ", " + topping_[index];
        
    }

    for (int index = 1; index < proteins_.size(); index++) {
        proteins = proteins_[index];
        proteins = proteins + ", " + proteins_[index];
    }

    for (int index = 1; index < sauce_.size(); index++) {
        //print index 0, store in sauce string
        sauces = sauce_[0];
        sauces = sauces + ", " + sauce_[index];
    }

    for (int index = 1; index < top_off_.size(); index++) {
        topOffs = top_off_[0];
        topOffs = topOffs + ", " + top_off_[index];
    }
    // this is so incredibly ineffiencet i know, will return after i finish everything bc im lazy


    return ("You ordered a " + size_ + " bowl with " + base_ + ". For your toppings you chose " + toppings + ". For proteins you chose " +
    proteins + " with sauces " + sauces + ". To top it off, you chose " + topOffs + ".\n"); // convert vector to string, print
}

    void setOrder(int size, double proteins, double toppings, double sauces) {}

    double pokeBowl::calculateOrder(double size, double proteins, double toppings, double sauces) {
    // read the receipt/order
    // calculate it by inputting size and any extras
    // if size 
    this->size_ = size;


}
    






void pokePath() { //PATHWAY

    std::cout << "Welcome to Super Poke. Go start working";
}