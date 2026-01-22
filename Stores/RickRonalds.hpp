#ifndef RICKRONALDS_HPP
#define RICKRONALDS_HPP
#include <iostream>
#include <vector>

class rickMenu {
    public:

    rickMenu();
    
    // method 1: choices from 1-3
    // other function determines if 1 then this type, if 2 then this type 

    private:
    std::unordered_map<std::string, double> items;

};

class rickOrder {
    public:

    void generateNPCOrder();
    void calculateOrderTotal();
    void printOrder();
    //RNG ORDER
    
    
    private:
    rickMenu menu_;
    registerSys POS_;
    std::vector<std::string> npcOrder_;
    std::vector<std::string> burgers_;
    std::vector<std::string> fries_;
    std::vector<std::string> drinks_;
    std::vector<std::string> extraAndDessert_;
    
};
#endif