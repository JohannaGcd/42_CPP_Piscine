#include "Harl.hpp"

int main(int argc, char **argv) {

    if (argc == 2) 
    {
        Harl harl;

        harl.complain(argv[1]);
    }
    else
        std::cout << "Usage: Enter a number between 0 and 3." << std::endl;

    return 0;
}