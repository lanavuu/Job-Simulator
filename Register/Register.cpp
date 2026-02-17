#include "Register.hpp"
#include "../Stores/SuperPoke.hpp"

#include <iostream>
#include <iomanip>

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

double registerSys::change(double orderCost, double customerMoney) {
    // Takes the order cost and customer's money and outputs the change needed
   
    return (customerMoney - orderCost);

}
// TODO: Compare the change, if user input == rng input then continue
// else repeat until user puts in the correct change
bool registerSys::compareChange(double amountDue, double userGiven) {
    // takes the due amount for the order and what the user gave to check if 
    // user gave the right change

    return amountDue == userGiven;

}

bool registerSys::compareCardInput(double amountDue, double cardAmount) {
    // checks if user input the correct due amount for the bowl with their card

    return amountDue == cardAmount;
}

