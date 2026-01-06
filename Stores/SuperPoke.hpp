#ifndef SUPERPOKE_HPP
#define SUPERPOKE_HPP


#include <string>
#include <vector>
#include <unordered_map>

// pause here come back to this file only. implement pokebowl class and soon add the hashmap in the main to the class for better
// class pokebowl manages the items and calculate total cost
// pokepath is just scanning and stuff dont forget

void pokePath();

class pokeBowl { //making a bowl, this is not the restaurant
    public:
    // when making a poke bowl, you choose size which determines the amount of protein.
    // when you choose the size, you choose your base.
    // after your base, you choose topping
    // after toppings, you choose your protein(s) then sauce
    // top it off at the end

    //size S M L
    // base: white rice, brown rice, spring mix
    // topping: crabmeat, spicy crabmeat, seaweed salad, cucumber, edamame, corn, onions, mango, pickled radish, avacado
    // protein: salmon, spicy salmon, tuna, spicy tuna, octopus, shrimp, scallop, yellowtail
    // sauce: soy sauce, super sauce, ponzu, spicy mayo, eel sauce, spicy ponzu
    // top off: fish eggs, cilantro, green onions, pineapple, wasabi, ginger, furikake, sesame seeds, fried shallots


    // NO MONEY, PAYMENT, OR CHANGE
    // NO MONEY, PAYMENT, OR CHANGE
        
    // NO MONEY, PAYMENT, OR CHANGE
    // NO MONEY, PAYMENT, OR CHANGE

    pokeBowl(); // completely new bowl, empty not chosen

    void pickSize();
    void pickBase();
    void pickTopping();
    void pickProteins();
    void pickSauce();
    void topItOff();
    std::string printOrder();
    double calculateOrder();
    void setSize(std::string& size);
    void buildBowl(); // helper function
    /*
    void setOrder(int size, double proteins, double toppings, double sauces);
    bool extras(); 
    */

    private: // these come from RNG, DONT PUT THEM IN THE CONSTRUCTOR.
    std::string size_; 
    std::string base_;
    std::vector<std::string> proteins_; //sizze can change buckaroo
    std::vector<std::string> topping_;
    std::vector<std::string> top_off_;
    std::vector<std::string> sauce_;
    int price_;
    paymentType customerPayment_;


    /*
    const double extra_proteins_ = .90;
    const double extra_toppings_ = .50;
    const double extra_sauces_ = .05;
    */

};

#endif