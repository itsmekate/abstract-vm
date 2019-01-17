#include "Lexer.hpp"

//Lexer::Lexer(){}

Lexer::~Lexer(){}

//std::vector<std::string> Lexer::readFromStdin()
//{
//    std::string input_line;
//    while (std::cin)
//    {
//        std::getline(std::cin, input_line);
//        this->file.push_back(input_line);
//    }
//}

//std::vector<std::string> Lexer::readFromFile(char *argv)
Lexer::Lexer()
{
    std::string input_line;
    std::ifstream infile;
//    infile.open (argv);
    infile.open ("test");
    while(!infile.eof())// To get you all the lines.
    {
        getline(infile, input_line); // Saves the line in STRING.
        this->file.push_back(input_line);
        //td::cout << str; // Prints our STRING.
    }
    infile.close();
}

std::vector<std::string> Lexer::getFile(){ return file; }