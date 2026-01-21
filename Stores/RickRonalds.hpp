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

class NPCOrder {
    public:

    //RNG ORDER
    
    private:
    std::vector<rickMenu> bag;
};
#endif