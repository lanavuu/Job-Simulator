#include "out-and-in.hpp"
#include <iostream>

#include <unordered_map>
//defn

int main () {
    std::unordered_map<std::string, int> OutMenu;

    OutMenu["Cheezburger"] = 5;
    OutMenu["Burger"] = 5;
    OutMenu["Fries"] = 2;
    OutMenu["Soda"] = 2;
    OutMenu["Smoothie"] = 3;
    OutMenu["Hot Chocolate"] = 2;

    std::cout << "This is our menu:\n";
    for (auto i : OutMenu) {
        std::cout << i.first << " $" << i.second << std::endl;
    }
    return 0;
}