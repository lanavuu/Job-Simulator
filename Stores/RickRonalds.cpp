#include "RickRonalds.hpp"
#include "../Register/Register.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <iomanip>

    rickOrder::rickOrder() {
        menuPtr = new rickMenu();

        burgers_.push_back("RickCheese Burger");
        burgers_.push_back("RickPlain Burger");
        burgers_.push_back("Rick-Double");
        burgers_.push_back("Swordfish burger");

        fries_.push_back("Small Fries");
        fries_.push_back("Medium Fries");
        fries_.push_back("Large Fries");

        drinks_.push_back("Soda");
        drinks_.push_back("Mango-banana Smoothie");
        drinks_.push_back("Strawberry-banana Smoothie");
        
        extraAndDessert_.push_back("Rick-OreoFlurry");
        extraAndDessert_.push_back("Rick-CookieFlurry");
        extraAndDessert_.push_back("4 pc RickNuggets");
        extraAndDessert_.push_back("10 pc RickNuggets");
        extraAndDessert_.push_back("20pc RickNuggets");
        extraAndDessert_.push_back("Small Fries");
        extraAndDessert_.push_back("Medium Fries");
        extraAndDessert_.push_back("Large Fries");
        
    }

    void rickOrder::generateNPCOrder() {
        int randomIndex;
        std::string randomBurgerIndex;
        std::string randomFriesIndex;
        std::string randomDrinksIndex;
        std::string randomExtrasIndex;

        randomIndex = rand() % burgers_.size(); // pick a random number from the size of the burger vector
        randomBurgerIndex = burgers_[randomIndex]; // store the random burger at the index of random
        npcOrder_.push_back(randomBurgerIndex); // put the random burger into the order

        randomIndex = rand() % fries_.size();
        randomFriesIndex = fries_[randomIndex];
        npcOrder_.push_back(randomFriesIndex);

        randomIndex = rand() % drinks_.size();
        randomDrinksIndex = drinks_[randomIndex];
        npcOrder_.push_back(randomDrinksIndex);

        randomIndex = rand() % extraAndDessert_.size();
        randomExtrasIndex = extraAndDessert_[randomIndex];
        npcOrder_.push_back(randomExtrasIndex);

    }
    double rickOrder::calculateOrderTotal() {
        double total = 0.0;
        for (const std::string& theItem : npcOrder_) { 
            total += menuPtr->getPrice(theItem);

        }
        return total;
    }
    void rickOrder::printOrder() {
        std::cout << "YOU: You ordered: ";
        for (int item = 0; item < npcOrder_.size(); item++) {
            std::cout << npcOrder_[item] + ", ";
            if (item == (npcOrder_.size() - 1)) {
                std::cout << "and " + npcOrder_[item] + ".\n";
            }
        }
    }

    double rickOrder::customerChange() {
        // generates RNG customer change by allowing rng to overpay with the minimum of
        // the order price + extra dollars + cents
        double change;
        change = price_ + ((rand() % 10) + ((rand() % 100) / 100.0));

        return change;
        
    }

    void rickOrder::setPrice(double price) {
        price = price_;
    }

    rickOrder::~rickOrder() {
        delete menuPtr;
        menuPtr = nullptr;
    }

    rickMenu::rickMenu() {
        //structured as a whole order
        items["RickCheese Burger"] = 2;
        items["RickPlain Burger"] = 2;
        items["Rick-Double"] = 5.67;
        items["Swordfish Burger"] = 2.5;
        items["4 pc RickNuggets"] = 3;
        items["10 pc RickNuggets"] = 4.5;
        items["20pc RickNuggets"] = 6;
        items["Small Fries"] = 3;
        items["Medium Fries"] = 5.67;
        items["Large Fries"] = 7;
        items["Soda"] = 2;
        items["Mango-banana Smoothie"] = 4.67;
        items["Strawberry-banana Smoothie"] = 4.67;
        items["Rick-OreoFlurry"] = 4.50;
        items["Rick-CookieFlurry"] = 4.67;
        items["The Rick-Double-Double Trouble"] = 9.67; // includes two Rick-Double burgers, one medium fries, 4pc nugget and soda.
        items["Rick's Hungry Combo"] = 14.67; // includes one rick-double burger, two large fries, one 20pc fries, one soda, and one rick flurry
        items["Rick Discount Combo"] = 5; // cheaper combo includes one RickCheese burger, one small fry, and a soda
        items["Rick's No Meat Combo"] = 6.77; // swordfish burger, medium fries, soda
}
    double rickMenu::getPrice(const std::string& itemName) {
        return items[itemName];
    }


    void rickPath() {
        registerSys POS;
        char choice = 'n';
        bool shift = true;


        while(shift) {
            double cost;
            double customerChange;
            std::string paymentString;
            int paymentPath = 0;
            paymentType type;
            double enterChange = 676767;
            double POSchange = 0;
            bool compareChange;
            bool compareCardInput;
            double userChangeInput = 676767;

            rickOrder order;
            order.generateNPCOrder();
            order.printOrder();
            cost = order.calculateOrderTotal();
            customerChange = order.customerChange();
            POSchange = POS.change(cost, customerChange);
            


            std::cout << "YOU: In total, that will cost $" << cost << ". Will that be cash or card?\n";

            
            int random = rand() % 100;  // rng cash or card
            if (random < 60) {
                type = paymentType::Cash;
                paymentString = "Cash";
                paymentPath = 1;
            } else {
                type = paymentType::Card;
                paymentString = "Card";
                paymentPath = 2;
            }
            POS.setPayment(type);
          

            if (paymentPath == 1) {
                while(!POS.compareChange(POSchange, enterChange)) {
                    POSchange = POS.change(cost, customerChange);
                    std::cout << std::fixed << std::setprecision(2) << "CUSTOMER: Cash, here is my change: $" << customerChange << ".\n";
                    std::cout << "***REGISTER: calculating change... Give $" << POSchange
                    << ".\n***REGISTER: Enter change: ";
                    std::cin >> userChangeInput;
                        if (POS.compareChange(POSchange, enterChange)) {
                            std::cout << "***REGISTER: Transaction successful!\n";
                            break;
                        } else {
                            std::cout << "***REGISTER: Transaction failed, enter the correct input.\n";
                        }
                
                }


                
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
    /*std::cout << "This is our menu: ";

    for (auto i : rickMenu) {
        std::cout <<i.first << " $" << i.second;
    }
*/
}
