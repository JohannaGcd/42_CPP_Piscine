
#include <iostream>
#include <string>

// trim whitespaces

void    args_to_upper(std::string str) {

    int i = 0;
    while (str[i])
    {
        if (std::islower((str[i])))
            str[i] = std::toupper(str[i]);
        std::cout << str[i];
        i++;
    }
}

int main(int argc, char **argv) {

    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        int i = 1;
        while (argv[i])
        {
            args_to_upper(std::string(argv[i]));
            i++;
        }
    }
    return (0);
}