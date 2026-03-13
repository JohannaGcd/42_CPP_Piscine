#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {

    std::string outfile = argv[1];
    outfile = outfile.append(".replace.txt");
    std::ifstream inputFile(argv[1], std::ios::in);
    std::ofstream outputFile(outfile, std::ios::out);
    std::string line;
    std::string s1;
    std::string s2;
    std::string sub;
    size_t len_s1;
    //size_t len_s2;
    size_t len_line;

    s1 = "une";
    s2 = "un";
    size_t pos = -1;
    len_s1 = s1.length();
   // len_s2 = s2.length();
    len_line = 0;

    // use compare to check is s1 = s2. if yes, return a new file unchanged. CHECK MAKEFILE in case not created; what happens if fclean. maybe i need to add if condition, *.replace.txt
    // check is s1 and s2 are both given
    // check if input file is given 

    if (!inputFile.is_open())
        std::cerr << "Error opening input file";
    if (!outputFile.is_open())
        std::cerr << "Error creating output file";
    while (std::getline(inputFile, line))
    {
        while ((pos = line.find(s1, pos + 1)) != std::string::npos)
        {
            sub = line.substr(len_line, pos - len_line);
            sub.append(s2);
            outputFile << sub;
            len_line = pos + len_s1;
        }
        if (len_line < line.length())
        {
            outputFile << line.substr(len_line);
        }
    }
    // how to print remaining str ?

    //s3 = "il etait une fois une petite fille qui s'appelait gertrude. une journee de printemps, elle partit a la montagne.";

    // size_t pos = -1;
    // while ((pos = s3.find(s1, pos + 1)) != std::string::npos)
    // {
    //     if (pos) !=

    // }
    outputFile.close();
    inputFile.close();
    return (0);
}