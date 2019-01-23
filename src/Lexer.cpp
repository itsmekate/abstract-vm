#include "Lexer.hpp"
#include "Exception.hpp"

Lexer::Lexer(){
    instrNoValue = (R"(^(pop|dump|add|sub|mul|div|mod|print|exit)\s*([;].*)*)");
    instrValue = (R"(^(push|assert)\s(int8|int16|int32)(\()([\-]?\d+)(\))\s*([;].*)*)");
    instrValueDF = (R"(^(push|assert)\s(float|double)(\()([\-]?\d+\.\d+)(\))\s*([;].*)*)");
    comment = (R"(\s*[;].*)");
    emptyStr = (R"(^$)");
}

Lexer::~Lexer(){}

//Lexer(Lexer const & rhs){
//
//}
//Lexer			&operator=( Lexer const &rhs){
//
//}

std::vector<std::map<std::string, std::string>> Lexer::getFile(){ return file;}

//std::vector<std::string> Lexer::getErrors(){ return errors;}

void Lexer::readFromStdin()
{
    std::string input_line;
    int i = 0;
    while (std::cin)
    {
        if (input_line == ";;")
            return ;
        std::getline(std::cin, input_line);
        checkLine(input_line, i);
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
            checkLine(input_line, i);
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
    if (std::regex_match (str, match, instrValue) ||
        std::regex_match (str, match, instrNoValue) ||
        std::regex_match (str, match, instrValueDF) ||
        std::regex_match (str, match, comment)){
        std::map<std::string, std::string> line;
        line["cmd"] = match[1];
        line["type"] = match[2];
        line["value"] = match[4];
        file.push_back(line);
        return 1;
    }
    else if(std::regex_match (str, emptyStr))
        return 0;
    else {
        this->errors.push_back("Lexical Error in line: " + std::to_string(i));
        std::cout << "Lexical Error in line: " + std::to_string(i) << " " << str << std::endl;
        return 0;
    }
}