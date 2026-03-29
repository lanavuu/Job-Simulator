#ifndef RICKRONALDS_HPP
#define RICKRONALDS_HPP
#include <iostream>
#include <vector>
#include <unordered_map>

void rickPath();

class rickMenu {
    public:

    rickMenu();
    
    // method 1: choices from 1-3
    // other function determines if 1 then this type, if 2 then this type 
    double getPrice(const std::string&);

    private:
    std::unordered_map<std::string, double> items;

};

class rickOrder {
    public:
    rickOrder();
    ~rickOrder();

    void generateNPCOrder();
    double calculateOrderTotal();
    std::string printOrder();
    double customerMoney();
    void setPrice(double price);
    

    //RNG ORDER
    
    
    private:
    rickMenu* menuPtr;

    double price_;

    std::vector<std::string> npcOrder_;
    std::vector<std::string> burgers_;
    std::vector<std::string> fries_;
    std::vector<std::string> drinks_;
    std::vector<std::string> extraAndDessert_;
    
};

class OutOfRange{};
class IncorrectInput{};
#endif