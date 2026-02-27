
#include <iostream>
//#include <cctype>
#include <string>

void    args_to_upper(std::string argv) {
    int i = 0;
    while (argv[i])
    {
        if (std::islower(argv[i])) // check with std::islower(static_cast<unsigned char>(c)) for weird behaviors while testing
            argv[i] = std::toupper(argv[i]);
        std::cout << argv[i];
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        int i = 1;
        while (argv[i])
        {
            args_to_upper(std::string(argv[i]));
            std::cout << " ";
            i++;
        }
            
    }
    return (0);
}