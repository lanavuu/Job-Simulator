#include "Register.hpp"

#include <iostream>

registerSys::registerSys() 
: penny_(1), nickel_(5), dime_(10), quarter_(25)


{ // use initialzier because its a const. future ref, using this is best with const and references
    std::cout << "hola";
}