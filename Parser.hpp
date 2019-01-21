#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <string>
#include<map>
class Parser {
    public:
        Parser();
        Parser(std::vector<std::map<std::string, std::string>> lexer_result);
        ~Parser();
        void checkExit(std::vector<std::map<std::string, std::string>> file);
        void checkValue(std::map<std::string, std::string> i) const;
        void checkInt8( std::string const & value ) const;
        void checkInt16( std::string const & value ) const;
        void checkInt32( std::string const & value ) const;
        void checkFloat( std::string const & value ) const;
        void checkDouble( std::string const & value ) const;

    private:
};

#endif