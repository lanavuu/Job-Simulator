
#include "Stores/RickRonalds.hpp"
#include "Stores/SuperPoke.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(nullptr)); //rand seed ONCE in main
    while (true){

    std::cout << "Hey kid. You've got no money, no talent, no potential, and your parents hate you.\n";
    std::cout << "Imma take you in, but if you don't get no job then you're out of here.\n";
    std::cout << "Don't even come to me for advice, figure it out yourself. Go get a job and quit complaining.\n";

    int choice;
    std::cout << "Apply to: \n";
    std::cout << "1. RickRonalds, $20/hr\n";
    std::cout << "2. Super-Poke, $16.50/hr\n";
    std::cout << "3. Quit\n";
    std::cout << "Enter number: \n";
    std::cin >> choice;

    if (choice == 1) {
        rickPath();
    } else if (choice == 2) {
        pokePath();
    } else if (choice == 3){
        break;
    } else {
        std::cout << "Invalid, choose either 1-3.\n"; // back
    }
    return 0;
}
}