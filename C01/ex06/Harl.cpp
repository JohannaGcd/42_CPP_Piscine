#include "Harl.hpp"

/*
* *************** Constructors *************** 
*/

Harl::Harl () {};

/*
* *************** Helper Functions *************** 
*/

int convert_level(std::string level) {
    if (level == "0" || level == "DEBUG")
        return 0;
    else if (level == "1" || level == "INFO")
        return 1;
    else if (level == "2" || level == "WARNING")
        return 2;
    else if (level == "3" || level == "ERROR")
        return 3;
    else
        return -1;
};

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

    int lvl = convert_level(level);

    if (lvl != -1) {

        switch (lvl) {
            case 0:
                this->debug();
                this->info();
                this->warning();
                this->error();
                break;
            case 1:
                this->info();
                this->warning();
                this->error();
                break;
            case 2:
                this->warning();
                this->error();
                break;
            case 3:
                this->error();
                break;
        }
    }
    else
        std::cout << "Usage: Input level between 0 and 3 (ex: '0' or 'DEBUG')"  << std::endl;

}

    