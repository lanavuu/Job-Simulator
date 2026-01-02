#include "out-and-in.hpp"
#include <iostream>

#include <unordered_map>
//defn

int outpath () {
    std::unordered_map<std::string, double> outMenu;

    outMenu["Cheezburger"] = 5;
    outMenu["Burger"] = 5;
    outMenu["Protein Burger"] = 5;
    outMenu["Fries"] = 2;
    outMenu["Soda"] = 2;
    outMenu["Vanilla Shake"] = 3;
    outMenu["Chocolate Shake"] = 3;
    outMenu["Strawberry Shake"] = 3;
    outMenu["Hot Chocolate"] = 2;
    outMenu["Animal Fries"] = 5;

    std::cout << "This is our menu:\n";
    for (auto i : outMenu) {
        std::cout << i.first << " $" << i.second << std::endl;
    }
    return 0;
}