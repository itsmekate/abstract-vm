#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

class Lexer
{
    public:
        Lexer();
        ~Lexer();

    std::vector<std::string> getFile();

    void readFromStdin();
    void readFromFile(char *argv);
    
    int checkLine(std::string str);

    private:
        std::vector<std::string> file;
};

#endif