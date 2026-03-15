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
    if (level == "0" || level == "DEBUG")
        this->debug();
    else if (level == "1" || level == "INFO")
        this->info();
    else if (level == "2" || level == "WARNING")
        this->warning();
    else if (level == "3" || level == "ERROR")
        this->error();
    else
        std::cout << "Usage: Input level between 0 and 3 (ex: '0' or 'DEBUG')" << std::endl;
}