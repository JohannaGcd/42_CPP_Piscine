#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {

    if (argc == 4)
    {
        std::string line;
        std::string s1;
        std::string s2;
        std::string sub;
        size_t len_str;
        size_t len_line;
        size_t pos;

        std::ifstream inputFile(argv[1], std::ios::in);
        if (!inputFile)
        {
            std::cerr << "Error opening input file" << std::endl;
            return (1);
        }

        std::string outfile = argv[1];
        outfile = outfile.substr(0, outfile.find_last_of(".")).append(".replace.txt");
        std::ofstream outputFile(outfile, std::ios::out);

        s1 = argv[2];
        s2 = argv[3];
        pos = -1;
        len_str = std::max(s1.length(), s2.length());
        len_line = 0;

        if (!inputFile.is_open())
            std::cerr << "Error opening input file" << std::endl;
        if (!outputFile.is_open())
            std::cerr << "Error creating output file" << std::endl;
        
        while (std::getline(inputFile, line))
        {
            while ((pos = line.find(s1, pos + 1)) != std::string::npos)
            {
                sub = line.substr(len_line, pos - len_line);
                sub.append(s2);
                outputFile << sub;
                len_line = pos + len_str;
            }
            if (len_line < line.length())
            {
                outputFile << line.substr(len_line);
            }
        }
        outputFile.close();
        inputFile.close();

        return (0);
    }
    else
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> <search_string> <replace_string>" << std::endl;
        return (1);
    }
}