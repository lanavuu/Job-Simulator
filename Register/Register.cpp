#include "Register.hpp"
#include "../Stores/SuperPoke.hpp"
#include "../Exceptions.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>

registerSys::registerSys() 
: penny_(1), nickel_(5), dime_(10), quarter_(25), paymentType_(paymentType::Cash)


{ // use initialzier because its a const. future ref, using this is best with const and references

}

paymentType registerSys::getPaymentType() const { 
    // function that helps randomize the payment type 

    return paymentType_;
}

void registerSys::setPayment(paymentType type) {
    // function that helps set RNG payment type

    paymentType_ = type;
}

int registerSys::change(int orderCost, int customerMoney) {
    // Takes the order cost and customer's money and outputs the change needed
   
    return (customerMoney - orderCost);

}
// TODO: Compare the change, if user input == rng input then continue
// else repeat until user puts in the correct change
bool registerSys::compareChange(int amountDue, int userGiven) {
    // takes the due amount for the order and what the user gave to check if 
    // user gave the right change

    return amountDue == userGiven;

}

bool registerSys::compareCardInput(int amountDue, int cardAmount) {
    // checks if user input the correct due amount for the bowl with their card

    return amountDue == cardAmount;
}

int registerSys::toCents(double amount) const {
    //round the amount to be careful with storing values
    return static_cast<int>(std::round(amount * 100));
}

void registerSys::printMoney(int cents){
    //to print it like a double
    std::cout << "$" << std::fixed << std::setprecision(2) << cents / 100.0;
}

int registerSys::collectMoney(int amountDue){
    int current = 0;
    int choice;
    while(current != amountDue){
        try{
            std::cout << "\nSYSTEM: amount due = ";
            printMoney(amountDue);
            std::cout << "\nSYSTEM: current = ";
            printMoney(current);
            std::cout << "\nSYSTEM: Please enter the correct amount of change:\n1. Add $10.00\n2. Add $5.00\n3. Add $1.00\n4. Add $0.25\n5. Add $0.10\n6. Add $0.05\n7. Add $0.01\n";
            std::cin >> choice;
            if (choice < 1 || choice > 7) {
                throw OutOfRange();
            }
            else if (choice == 1){
                current += 1000;
            }
            else if (choice == 2){
                current += 500;
            }
            else if (choice == 3){
                current += 100;
            }
            else if (choice ==4){
                current+=25;
            }
            else if (choice == 5){
                current+=10;
            }
            else if(choice==6){
                current+=5;
            }
            else if(choice==7){
                current+=1;
            }
            else if(current > amountDue){
                std::cout << "Error: Too much";
                

            }
        }
        catch (const OutOfRange){
            std::cout << "Error: Invalid input, enter 1-9.";
        }
    }
}