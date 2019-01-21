#include "Exception.hpp"

const char *wrongValue::what() const throw()
{
    return "Value is incorrect";
}

const char *divisionByZero::what() const throw()
{
    return "Division by Zero exception";
}
//
//const char *lexicalError::what() const throw()
//{
//    return "Lexical Error:";
//}
const char *noExit::what() const throw()
{
    return "No Exit Statement";
}

const char *incorrectInput::what() const throw()
{
    return "Wrong input arguments";
}