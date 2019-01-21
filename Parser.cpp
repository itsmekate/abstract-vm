#include "Parser.hpp"
#include "Exception.hpp"

#include <limits.h>
#include <iostream>

Parser::Parser(std::vector<std::map<std::string, std::string>> lexer_result){
    try
    {
        checkExit(lexer_result);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

Parser::~Parser(){}

void Parser::checkExit(std::vector<std::map<std::string, std::string>> file){
    int exit = 0;
    for(auto &i : file){
        if (i["cmd"] == "exit")
            exit++;
        else if (i["cmd"] == "push" || i["cmd"] == "assert")
            checkValue(i);
    }
    if (exit != 1)
        throw noExit();
}

void Parser::checkValue(std::map<std::string, std::string> i) const {
    if (i["type"] == "int8")
        checkInt8(i["value"]);
    else if (i["type"] == "int16")
        checkInt16(i["value"]);
    else if (i["type"] == "int32")
        checkInt32(i["value"]);
    else if (i["type"] == "float")
        checkFloat(i["value"]);
    else if (i["type"] == "double")
        checkDouble(i["value"]);
}

void Parser::checkInt8( std::string const & value ) const {
    try {
        int i = std::stoi(value);
        if (CHAR_MIN > i || i > CHAR_MAX)
            throw wrongValue();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
void Parser::checkInt16( std::string const & value ) const {
    try
    {
        int i = std::stoi(value);
        if (SHRT_MIN > i || i > SHRT_MAX)
            throw wrongValue();
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
void Parser::checkInt32( std::string const & value ) const {
    try
    {
        int i = std::stoi(value);
        if (INT_MIN > i || i > INT_MAX)
            throw wrongValue();
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
void Parser::checkFloat( std::string const & value ) const {
    try
    {
        float i = std::stof(value);
        if (std::numeric_limits<float>::max() < i || i < std::numeric_limits<float>::lowest())
            throw wrongValue();
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
void Parser::checkDouble( std::string const & value ) const {
    try
    {
        double i = std::stod(value);
        if (std::numeric_limits<double>::max() < i || i < std::numeric_limits<double>::lowest())
            throw wrongValue();
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}