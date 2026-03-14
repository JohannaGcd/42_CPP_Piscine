#include "Harl.hpp"

// swtich table ?

int main(int argc, char **argv) {

    if (argc == 2) 
    {
        Harl harl;

        harl.complain(argv[1]);
        
        // switch (value) {
        //     case 1:
        //         void (Harl::*complain[0])() = &Harl::debug;
        //     case 2:
        //     case 3:
        //     case 4:
        //     default:
        //         std::cout << "Input a number between 0 and 3." << std::endl;
        // }
    }

    else
        std::cout << "Usage: Enter a number between 0 and 3." << std::endl;

    return 0;
}