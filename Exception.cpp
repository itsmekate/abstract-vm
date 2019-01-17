#include "Exception.hpp"

const char *notInt8::what() const throw()
{
    return "not an Int8 value";
}

const char *notInt16::what() const throw()
{
    return "not an Int16 value";
}

const char *notInt32::what() const throw()
{
    return "not an Int32 value";
}

const char *notFloat::what() const throw()
{
    return "not a Float value";
}

const char *notDouble::what() const throw()
{
    return "not a Double value";
}

const char *divisionByZero::what() const throw()
{
    return "Division by Zero exception";
}