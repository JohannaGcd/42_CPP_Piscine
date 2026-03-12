#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>

int main(void) {

    // then do it in a different file
    // then replace substring in a string
   
    std::ifstream inputFile("file.txt");
    std::string line;
    std::string s1;
    std::string s2;
    std::string sub;

    s1 = "une";
    s2 = "un";
    size_t pos = -1;

    while (std::getline(inputFile, line))
    {
        while ((pos = line.find(s1, pos + 1)) != std::string::npos)
        {
            std::cout << pos << " " << std::endl;
            sub = line.substr(pos) // here figure out how to substr
        }

    }
    //s3 = "il etait une fois une petite fille qui s'appelait gertrude. une journee de printemps, elle partit a la montagne.";

    // size_t pos = -1;
    // while ((pos = s3.find(s1, pos + 1)) != std::string::npos)
    // {
    //     if (pos) !=

    // }

    return (0);
}