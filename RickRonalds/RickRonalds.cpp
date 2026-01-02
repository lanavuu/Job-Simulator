#include "RickRonalds.hpp"
#include <iostream>

#include <unordered_map>

int rickPath() {
    std::unordered_map<std::string, double> rickMenu;

    rickMenu["Cheese Burger"] = 2;
    rickMenu["Plain Burger"] = 2;
    rickMenu["Swordfish Burger"] = 2.5;
    rickMenu["4 pc RickNuggets"] = 3;
    rickMenu["10 pc rickNuggets"] = 4.5;
    rickMenu["20pc rickNuggets"] = 6;
    rickMenu["Small Fries"] = 3;
    rickMenu["Medium Fries"] = 5.67;
    rickMenu["Large Fries"] = 7;
    rickMenu["Soda"] = 2;
    rickMenu["Mango-banana Smoothie"] = 4.67;
    rickMenu["Strawberry-banana Smoothie"] = 4.67;

    std::cout << "This is our menu: ";

    for (auto i : rickMenu) {
        std::cout << i.first << " $" << i.second;
    }


    return 0;
}