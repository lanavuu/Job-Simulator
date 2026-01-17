#include "SuperPoke.hpp"
#include "../Register/Register.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>


#include <unordered_map>

pokeBowl::pokeBowl() { // pokebowl is a member of the pokebowl class, compile knows where all the private members come from
    size_ = "";
    base_ = "no base";

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
    topping_.clear();
    int toppingMax;
    std::vector<std::string> toppings = {"crabmeat", "spicy crabmeat", "seaweed salad", "cucumber", "edamame", "corn",
    "onions", "mango", "pickled radish", "avacado"};
    //how do i store up to five toppings? -> turn into a list
    // randomly choose max amount of topping
    toppingMax = 1 + rand() % 5; // randomly choose amount of toppings 1-5
    // store random toppings into topping_ (toppingMax) amount of times

    for (size_t index = 0; index < toppingMax; index++) {
        topping_.push_back(toppings[rand() % 10]); //I FORGOT THIS DOES NOT HAVE ANYTHING IN IT
        //for current index at topping
        // push random item onto the vector
        // continue until for loop logic breaks
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
    for (size_t index = 0; index < proteinMax; index++) {
        proteins_.push_back(proteins[rand() % 8]);// i randomly selects from proteins vector and keeps storing proteins 
                                                    // until it reaches the max proteins
    } // fixed

}

void pokeBowl::pickSauce() { // up to 3 sauzes max
    int sauceMax;
    std::vector<std::string> sauces {"soy sauce", "super sauce", "ponzu", "spicy mayo", "eel sauce", "spizy ponzu"};

    sauceMax = rand() % 3;
    for (size_t index = 0; index < sauceMax; index++) {
        sauce_.push_back(sauces[rand() % 6]); //fixed
    }

}


void pokeBowl::topItOff() { //forgot top offs
    int topOffMax;
    std::vector<std::string> topOffs = {"fish eggs", "cilantro", "green onions", "pineapple", "wasabi", "ginger", "furikake", "sesame seeds", "fried shallots"};
    
    topOffMax = 1 + rand() % 9;
    for (size_t index = 0; index < topOffMax; index++) {
        top_off_.push_back(topOffs[rand() % 9]);
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


    return ("CUSTOMER RECIPT: Customer ordered a " + size_ + " bowl with " + base_ + ".\n For your toppings you chose " + toppings + ".\n For proteins you chose " +
    proteins + " with sauces " + sauces + ".\n To top it off, you chose " + topOffs + ".\n"); // convert vector to string, print
}
    void pokeBowl::setSize (std::string& size) {
        size_ = size;
    } // need to set the size for order calculations
    
    // scrap for now, work on simplier methods first.
    /*
    bool extras() {

    }

    void setOrder(int size, double proteins, double toppings, double sauces) {}
    */
    double pokeBowl::calculateOrder() {
    // read the receipt/order
    // calculate it by inputting size and any extras
    // if statements, cant grasp my idea, trying this first

        if (size_ == "Small") {
            price_ = 14;
            std::cout << "YOU: Okay you ordered a small, that will be $14 please\n";
            return price_;
        } else if (size_ == "Medium") {
            price_ = 17;
            std::cout << "YOU: Okay you ordered a small, that will be $14 please\n";
            return price_;
        } else if (size_ == "Large") {
            price_ = 20;
            std::cout << "YOU: Okay you ordered a small, that will be $14 please\n";
            return price_;
        } else {
        std::cout << "Invalid order\n";
        }
       

return price_;
}

    void pokeBowl::buildBowl() { //random bowl
        pickSize();
        pickBase();
        pickTopping();
        pickProteins();
        pickSauce();
        topItOff();
    }

    double pokeBowl::customerChange() {
        double change;
        change = price_ + rand() % 10;
        return change;
    }
    






void pokePath() { //PATHWAY

    registerSys POS;

    char choice = 'n';
    bool shift = true;

    // while clock in, run cashier simulator and fnctions
    // if clock out, break out of loop then ask "go home?" quit job option

    //create new bowl for each new customer

    while (shift) {
        std::string paymentString;
        double changeAmount;
        paymentType type;
        double enterChange;
        double change;

        pokeBowl bowl; //create a bowl object
        bowl.buildBowl(); // randomly build new bowl
        std::cout << bowl.printOrder(); // print the order
        double order = bowl.calculateOrder(); // calculate the price of the bowl

        int random = rand() % 100;  // rng cash or card
        if (random < 80) {
            type = paymentType::Cash;
            paymentString = "Cash";
        } else {
            type = paymentType::Card;
            paymentString = "Card";
        }

        POS.setPayment(type);
        changeAmount = bowl.customerChange();

        std::cout << "Customer: I am paying with " << paymentString << "\nHere is my money: $" 
        << std::fixed << std::setprecision(2) << changeAmount << ".\n"; // got the payment
        std::cout << "REGISTER: You owe: " << POS.change(bowl.customerChange(), order) << "\n"; //register function
        std::cout << "REGISTER: Enter the right amount of change to give back: \n";
        std::cin >> enterChange;


       //if change is correct, proceed, if not repeat until correct for now

       while (!POS.compareChange(changeAmount, enterChange)) { //NOT PYTHON
        std::cout << "Please try again.\n";
        std::cin >> enterChange;
       } 
       std::cout << "Transaction completed!\n";

    }

    std::cout << "CLOCK OUT?\n";
    std::cout << "Enter 'y' or 'n': \n ";
    std::cin >> choice;
    choice = std::tolower(choice);
    if (choice == 'y') {
        std::cout << "Bye!\n";
        shift = false;

    } else {
        std::cout << "Keep working.\n";
    } 

}