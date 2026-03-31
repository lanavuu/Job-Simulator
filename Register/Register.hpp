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

    int change(int orderCost, int customerMoney);
    void setPayment(paymentType type);
    paymentType getPaymentType() const;
    bool compareChange(int amountDue, int userGiven);
    bool compareCardInput(int amountDue, int cardAmount);
   
    int toCents(double amount) const;
    void printMoney(int cents);
    int collectMoney(int amountDue);





    private:
    const int penny_;
    const int nickel_;
    const int dime_;
    const int quarter_;
    const int dollar_ = 100;
    const int fiveDollar_ = 500;
    const int tenDollar_ = 1000;
    paymentType paymentType_; // custom type paymentType, only holding values from enum class paymentType


};
#endif