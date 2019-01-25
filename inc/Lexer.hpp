#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <map>

class Lexer
{
    public:
        Lexer();
        ~Lexer();
        Lexer(Lexer const & rhs);
        Lexer			&operator=( Lexer const &rhs);

        std::vector<std::map<std::string, std::string>> getFile();
        std::vector<std::string> getErrors();

        void readFromStdin();
        void readFromFile(char *argv);

        int checkLine(std::string str, int i);

    private:

        std::vector<std::map<std::string, std::string>> file;
        std::vector<std::string> errors;
        std::smatch match;

        std::regex instrNoValue;
        std::regex instrValue;
        std::regex instrValueDF;
        std::regex comment;
        std::regex emptyStr;
};

#endif