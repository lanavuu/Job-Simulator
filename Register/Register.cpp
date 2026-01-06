#include "Register.hpp"

#include <iostream>

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

double registerSys::change(double order) {

    if (paymentType_ == paymentType::Cash) {
        return "You owe: " + ()
    }

}

