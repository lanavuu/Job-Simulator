#include "Register.hpp"
#include "../Stores/SuperPoke.hpp"

#include <iostream>
#include <iomanip>

registerSys::registerSys() 
: penny_(1), nickel_(5), dime_(10), quarter_(25), paymentType_(paymentType::Cash)


{ // use initialzier because its a const. future ref, using this is best with const and references

}

paymentType registerSys::getPaymentType() const { //returning cash or card
    return paymentType_;
}

void registerSys::setPayment(paymentType type) {
    paymentType_ = type;
}

double registerSys::change(double orderCost, double customerMoney) {
 
    std::cout << std::fixed << std::setprecision(2) 
    << "\nThe bowl costs: $" << orderCost
    << "\nCustomer gave: $" << customerMoney << "\n" << customerMoney << " - "
    << orderCost << " = $" <<
    (customerMoney - orderCost) << "\n";
   
    return (customerMoney - orderCost);

}
// TODO: Compare the change, if user input == rng input then continue
// else repeat until user puts in the correct change
bool registerSys::compareChange(double amountDue, double userGiven) {
    return amountDue == userGiven;

}

bool registerSys::compareCardInput(double amountDue, double cardAmount) {
    return amountDue == cardAmount;
}

