#include "Harl.hpp"

/*
* *************** Constructors ***************
*/

Harl::Harl() {};

/*
* *************** Private Methods *************** 
*/

void Harl::debug (void) {
    std::cout << "DEBUG message is printed." << std::endl;
}

void Harl::info (void) {
    std::cout << "INFO message is printed." << std::endl;
};

void Harl::warning (void) {
    std::cout << "WARNING message is printed." << std::endl;
};

void Harl::error (void) {
    std::cout << "ERROR message is printed." << std::endl;
};

/*
* *************** Public Methods *************** 
*/

void Harl::complain (std::string level) {

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*complaintLevel[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error 
    };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*complaintLevel[i])();
    }    
}