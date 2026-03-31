#include "RickRonalds.hpp"
#include "../Register/Register.hpp"
#include "../Exceptions.hpp"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <iomanip>
#include <cmath>

    rickOrder::rickOrder() {
        menuPtr = new rickMenu();

        burgers_.push_back("RickCheese Burger");
        burgers_.push_back("RickPlain Burger");
        burgers_.push_back("Rick-Double");
        burgers_.push_back("Swordfish Burger");

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
    std::string rickOrder::printOrder() {
        std::string result = "";
        for (int item = 0; item < npcOrder_.size(); item++){
            if(item == npcOrder_.size() -1){
                result += "and " + npcOrder_[item] + '.';
            }
            else{
                result += npcOrder_[item] + ", ";
            }
        }
        return result;
    }

    double rickOrder::customerMoney() {
        // generates RNG customer change by allowing rng to overpay with the minimum of
        // the order price + extra dollars + cents
        double change;
        change = price_ + ((rand() % 10) + ((rand() % 100) / 100.0));

        return change;
        
    }

    void rickOrder::setPrice(double price) {
        price_ = price;
        
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

void startShift();
void cashier();
void endingChoice();
    void rickPath() {

        while (true) {
            int choice = 99;
            try {
                std::cout << "Would you like to clock in?\nEnter [1] yes or [0] no: ";
                std::cin >> choice;
                if (choice < 0 || choice > 1) {
                    throw OutOfRange();
                }
                else if (choice == 1) {
                    startShift();
                    break;

                }
                else if (choice == 0) {
                    std::cout << "\nGoing home..";
                    break;
                }
            }
            catch (OutOfRange){
                std::cout << "Error: you entered a number other than 1 and 0.\n";
            }
            
        }

}
void startShift(){

    while (true){
        int action;
        try{
            std::cout << "1. Cashier\n2. Cook(LOCKED)\n3. Janitor(LOCKED)\n4. Manager(LOCKED)\n5. Clock out\nEnter your position: ";
            std::cin >> action;
            if (action < 1 || action > 5){
                throw OutOfRange();
            }
            else if (action == 1) {
                cashier();
                break;
            }
            if (action == 5) {
                rickPath();
                break;
            }
        }
        catch (OutOfRange){
            std::cout << "Error: you entered an invalid number\n";
        }
    }
}
void cashier(){
    while (true){
        registerSys POS;
        rickOrder randomOrder;
        int choice;

        randomOrder.generateNPCOrder();
        std::cout << "Hello welcome to rickronalds what do you want?\n";
        std::cout << "CUSTOMER: give me a " << randomOrder.printOrder() << "\n";

        double priceDollars = randomOrder.calculateOrderTotal();
        randomOrder.setPrice(priceDollars);
        int price = POS.toCents(priceDollars);

        std::cout << "SYSTEM: This order costs: ";
        POS.printMoney(price);
        std::cout << "\n";

        POS.printMoney(price);
        std::cout << " please.\n";

        int customerMoney = POS.toCents(randomOrder.customerMoney());
        std::cout << "CUSTOMER: Here is ";
        POS.printMoney(customerMoney);
        std::cout << "\n";
        while (true){
            try {
                std::cout << "\nSYSTEM: Enter the customers money: $";
                double inputCustomersMoney;
                std::cin >> inputCustomersMoney;

                int inputCustomersMoneyCents = POS.toCents(inputCustomersMoney);

                if (inputCustomersMoneyCents != customerMoney){
                    throw IncorrectInput();
                }
                else{
                    break;
                }
            }
            catch (IncorrectInput){
                std::cout << "Error: double check your input, try again.\n";
        }
        }
        while (true){
            try{
            int change = POS.change(price, customerMoney);
            std::cout << "SYSTEM: You owe the customer: ";
            POS.printMoney(change);
            std::cout << "\n";

            std::cout << "SYSTEM: Enter their change: ";
            double inputChange;
            std::cin >> inputChange;

            int inputChangeCents = POS.toCents(inputChange);

            if (!(POS.compareChange(change, inputChangeCents))){
                throw IncorrectInput();
            }
            else{
                std::cout << "+10 social credit\n";
                endingChoice();
                break;
            
            }
            }
            catch(IncorrectInput){
                std::cout << "Error: double check your input, try again.\n";
            }
        }
    }

}

void endingChoice() {
    while (true){
        try{
            int choice;
            std::cout << "Serve the next customer? [1] yes or [2] no: ";
            std::cin >> choice;
            std::cout << "\n";
            if (choice < 1 || choice >2){
                throw OutOfRange();
            }
            if (choice == 1){
                cashier();
                break;
            }
            else if (choice == 2){
                std::cout << "Returning to position choice..\n";
                startShift();
                break;
            }
        }
        catch(OutOfRange){
        std::cout << "Error: you entered an invalid number\n";
        }
    }
}