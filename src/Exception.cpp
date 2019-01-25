#include "../inc/Exception.hpp"

const char *wrongValue::what() const throw()
{
    return "Value is incorrect";
}

const char *divisionByZero::what() const throw()
{
    return "Division by Zero exception";
}

const char *lexicalError::what() const throw()
{
    return "Too many Lexical Errors to proceed";
}

const char *noExit::what() const throw()
{
    return "No Exit Statement";
}

const char *stackTooSmall::what() const throw()
{
    return "Stack Too Small";
}

const char *AssertError::what() const throw()
{
    return "Assert Error";
}

const char *incorrectInput::what() const throw()
{
    return "Exception opening/reading/closing file";
}