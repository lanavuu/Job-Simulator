#include "Register.hpp"
#include "../Stores/SuperPoke.hpp"

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