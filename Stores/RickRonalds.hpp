#ifndef RICKRONALDS_HPP
#define RICKRONALDS_HPP
#include <iostream>
#include <vector>

class rickMenu {
    public:

    rickMenu();
    std::string npcOrderBurger();
    std::string npcOrderNuggets();
    std::string npcLines();
    // method 1: choices from 1-3
    // other function determines if 1 then this type, if 2 then this type 

    private:
    std::unordered_map<std::string, double> items;
    std::vector<std::string> burger_;
    std::vector<std::string> nuggets_;
    std::vector<std::string> fries_;
    std::vector<std::string> drink_;
    bool iceCream_;
    std::vector<std::string> order_;

};

#endif