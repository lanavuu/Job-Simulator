#ifndef REGISTER_HPP
#define REGISTER_HPP
#include <unordered_map>
#include <iostream>
// define coins
// y? idk
// money is used for everything. 

// this class will allow user to give change by selecting the corrrect amount of coins and cash
// how to allow user to select the coins for change? 
// how to check if change is correct?
// what does calculating the order price do for this file?

// COIN VALUES
// CASH VS CARD
// CHANGE CALCULATION
// VALIDATING INPUT
// NO ORDERS
enum class paymentType { //paymenttype only accepts values either cash or card
    Cash,
    Card
};

class registerSys{
    public:
    registerSys();

    double change(double orderCost, double customerMoney);
    void setPayment(paymentType type);
    paymentType getPaymentType() const;
    bool compareChange(double amountDue, double userGiven);
    bool compareCardInput(double amountDue, double cardAmount);
   




    private:
    const int penny_;
    const int nickel_;
    const int dime_;
    const int quarter_;
    paymentType paymentType_; // custom type paymentType, only holding values from enum class paymentType


};
#endif