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
    std::vector<std::string> getErrors();

    void readFromStdin();
    void readFromFile(char *argv);
    
    int checkLine(std::string str, int i);

    private:
        std::vector<std::string> file;
        std::vector<std::string> errors;

        std::regex instrNoValue;
        std::regex instrValue;
        std::regex comment;
        std::regex emptyStr;
};

#endif