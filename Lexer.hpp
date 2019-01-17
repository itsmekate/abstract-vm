#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include <vector>

class Lexer
{
    public:
        Lexer();
        ~Lexer();

    std::vector<std::string> getFile();

//    std::vector<std::string> readFromStdin();
    std::vector<std::string> readFromFile(char *argv);

    private:
        std::vector<std::string> file;
};

#endif