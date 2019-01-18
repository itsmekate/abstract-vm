#include "Lexer.hpp"
#include "Exception.hpp"

Lexer::Lexer(){
    instrNoValue = (R"(^(pop|dump|add|sub|mul|div|mod|print|exit)\s*([;].*)*)");
    instrValue = (R"(^(push|assert)\s(int8|int16|int32|double|float)(\(\d{1,}(\.)?\d{1,}\))\s*([;].*)*)");
    comment = (R"(\s*[;].*)");
    emptyStr = (R"(^$)");
}

Lexer::~Lexer(){}

std::vector<std::string> Lexer::getFile(){ return file;}

std::vector<std::string> Lexer::getErrors(){ return errors;}

void Lexer::readFromStdin()
{
    std::string input_line;
    int i = 0;
    while (std::cin)
    {
        if (input_line == ";;")
            return ;
        std::getline(std::cin, input_line);
        if (checkLine(input_line, i))
            this->file.push_back(input_line);
        i++;
    }
}

void Lexer::readFromFile(char *argv)
{
    std::string input_line;
    std::ifstream infile;
    int i = 0;

    infile.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    try
    {
        infile.open (argv);
        while(!infile.eof())
        {
            getline(infile, input_line);
            if (checkLine(input_line, i))
                this->file.push_back(input_line);
//            else
//                throw lexicalError();
            i++;
        }
        infile.close();
    }
    catch (std::exception &e) {
        std::cout << "Exception opening/reading/closing file\n";
    }

}

int Lexer::checkLine(std::string str, int i)
{
    if (std::regex_match (str, instrValue) ||
        std::regex_match (str, instrNoValue) ||
        std::regex_match (str, comment)){
        return 1;
    }
    else if(std::regex_match (str, emptyStr))
        return 0;
    else {
        this->errors.push_back("Lexical Error in line: " + std::to_string(i));
        std::cout << "Lexical Error in line: " + std::to_string(i) << std::endl;
        return 0;
    }
}