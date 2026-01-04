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
class registerSys{
    public:
    registerSys();

    double change(double order);



    private:
    const int penny_;
    const int nickel_;
    const int dime_;
    const int quarter_;
    

};
#endif