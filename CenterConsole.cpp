#include "Stores/OutAndIn.hpp"
#include "Stores/RickRonalds.hpp"
#include "Stores/SuperPoke.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(nullptr)); //rand seed ONCE in main

    std::cout << "Hey kid. You've got no money, no talent, no potential, and your parents hate you.\n";
    std::cout << "Imma take you in, but if you don't get no job then you're out of here.\n";
    std::cout << "Don't even come to me for advice, figure it out yourself. Go get a job and quit complaining.\n";

    int choice;
    std::cout << "Apply to: \n";
    std::cout << "1. Out-and-in, $24/hr\n";
    std::cout << "2. RickRonalds, $20/hr\n";
    std::cout << "3. Super-Poke, $16.50/hr\n";
    std::cout << "Enter number: \n";
    std::cin >> choice;

    if (choice == 1) {
        outPath();
    } else if (choice == 2) {
        rickPath();
    } else if (choice == 3) {
        pokePath();
    } else {
        std::cout << "Invalid, choose either 1, 2, or 3."; // back
    }



    return 0;
}