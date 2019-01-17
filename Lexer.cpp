#include "Lexer.hpp"

Lexer::Lexer(){}

Lexer::~Lexer(){}

void Lexer::readFromStdin()
{
    std::string input_line;
    while (std::cin)
    {
        std::getline(std::cin, input_line);
        this->file.push_back(input_line);
    }
}

void Lexer::readFromFile(char *argv)
{
    std::string input_line;
    std::ifstream infile;
    infile.open (argv);
    while(!infile.eof())
    {
        getline(infile, input_line);
        this->file.push_back(input_line);
        if (checkLine(input_line))
            std::cout << "good\n";
    }
    infile.close();
}

std::vector<std::string> Lexer::getFile(){ return file; }

int Lexer::checkLine(std::string str)
{
//    std::vector<std::string> instr{ "push", "pop", "dump", "assert", "add", "sub", "mul", "div", "mod", "print", "exit"};
//    std::vector<std::string> value{"int8", "int16", "int32", "float", "double"};
//    std::string n = "[-]?[0..9]+";
//    std::string z = "[-]?[0..9]+.[0..9]+";
//    std::string sep = "'\n'+";
//    std::regex e (instr [sep value]*);
    if (std::regex_match (str, std::regex("[-]?[0..9]+.[0..9]+")))
        return 1;
    return 0;
}