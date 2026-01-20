#include "RickRonalds.hpp"
#include "../Register/Register.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>

rickMenu::rickMenu() {
    //structured as a whole order
    items["Cheese Burger"] = 2;
    items["Plain Burger"] = 2;
    items["Rick-Double"] = 5.67;
    items["Swordfish Burger"] = 2.5;
    items["4 pc RickNuggets"] = 3;
    items["10 pc rickNuggets"] = 4.5;
    items["20pc rickNuggets"] = 6;
    items["Small Fries"] = 3;
    items["Medium Fries"] = 5.67;
    items["Large Fries"] = 7;
    items["Soda"] = 2;
    items["Mango-banana Smoothie"] = 4.67;
    items["Strawberry-banana Smoothie"] = 4.67;
    items["Rick-Flurry"] = 4.50;
}
void rickPath() {
    std::unordered_map<std::string, double> rickMenu;


    /*std::cout << "This is our menu: ";

    for (auto i : rickMenu) {
        std::cout << i.first << " $" << i.second;
    }
*/
}