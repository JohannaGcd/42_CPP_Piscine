#include "Harl.hpp"

/*
* *************** Constructors *************** 
*/

Harl::Harl () {};

/*
* *************** Private Methods *************** 
*/

void Harl::debug (void) {

    std::cout << "[ DEBUG ]" << std::endl;

};

void Harl::info (void) {

    std::cout << "[ INFO ]" << std::endl;

};

void Harl::warning (void) {

    std::cout << "[ WARNING ]" << std::endl;

};

void Harl::error (void) {

    std::cout << "[ ERROR ]" << std::endl;

}; 

/*
* *************** Public Methods *************** 
*/

void Harl::complain (std::string level) {

    int i;

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            break;
    }

    switch (i)
    {
        case 0:
            debug();
            //FALLTRHOUGH
        case 1:
            info();
            //FALLTRHOUGH
        case 2:
            warning();
            //FALLTRHOUGH
        case 3:
            error();
            break;
        default:
            std::cout << "this is not a valid argument" << std::endl;
    }
}

    