#include "RickRonalds.hpp"
#include "../Register/Register.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

rickOrder::rickOrder() {
    burgers_.push_back("RickCheese Burger");
    burgers_.push_back("RickPlain Burger");
    burgers_.push_back("Rick-Double");
    burgers_.push_back("Swordfish burger");

    fries_.push_back("Small Fries");
    fries_.push_back("Medium Fries");
    fries_.push_back("Large Fries");

    drinks_.push_back("Soda");
    drinks_.push_back("Mango-banana Smoothie");
    drinks_.push_back("Strawberry-banana Smoothie");
    
    extraAndDessert_.push_back("Rick-OreoFlurry");
    extraAndDessert_.push_back("Rick-CookieFlurry");
    extraAndDessert_.push_back("4 pc RickNuggets");
    extraAndDessert_.push_back("Rick-OreoFlurry");
    extraAndDessert_.push_back("Rick-OreoFlurry");
    extraAndDessert_.push_back("Rick-OreoFlurry");



      
}

rickMenu::rickMenu() {
    //structured as a whole order
    items["RickCheese Burger"] = 2;
    items["RickPlain Burger"] = 2;
    items["Rick-Double"] = 5.67;
    items["Swordfish Burger"] = 2.5;
    items["4 pc RickNuggets"] = 3;
    items["10 pc RickNuggets"] = 4.5;
    items["20pc RickNuggets"] = 6;
    items["Small Fries"] = 3;
    items["Medium Fries"] = 5.67;
    items["Large Fries"] = 7;
    items["Soda"] = 2;
    items["Mango-banana Smoothie"] = 4.67;
    items["Strawberry-banana Smoothie"] = 4.67;
    items["Rick-OreoFlurry"] = 4.50;
    items["Rick-CookieFlurry"] = 4.67;
    items["The Rick-Double-Double Trouble"] = 9.67; // includes two Rick-Double burgers, one medium fries, 4pc nugget and soda.
    items["Rick's Hungry Combo"] = 14.67; // includes one rick-double burger, two large fries, one 20pc fries, one soda, and one rick flurry
    items["Rick Discount Combo"] = 5; // cheaper combo includes one RickCheese burger, one small fry, and a soda
    items["Rick's No Meat Combo"] = 6.77; // swordfish burger, medium fries, soda
}


void rickPath() {
    std::unordered_map<std::string, double> rickMenu;


    /*std::cout << "This is our menu: ";

    for (auto i : rickMenu) {
        std::cout <<i.first << " $" << i.second;
    }
*/
}
