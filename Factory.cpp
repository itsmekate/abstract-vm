#include "Factory.hpp"
#include "Exception.hpp"
#include "Operand.hpp"

#include<limits.h>

Factory::Factory(){}
Factory::~Factory(){}

IOperand const * Factory::createInt8( std::string const & value ) const {
	try
	{
		int i = std::stoi(value);
		if (CHAR_MIN > i || i > CHAR_MAX)
			throw notInt8();
		return new Operand<char>(value, Int8, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}
IOperand const * Factory::createInt16( std::string const & value ) const {
    try
    {
        int i = std::stoi(value);
        if (SHRT_MIN > i || i > SHRT_MAX)
            throw notInt16();
        return new Operand<short>(value, Int16, 0);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
IOperand const * Factory::createInt32( std::string const & value ) const {
    try
    {
        int i = std::stoi(value);
        if (INT_MIN > i || i > INT_MAX)
            throw notInt32();
        return new Operand<int>(value, Int32, 0);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
IOperand const * Factory::createFloat( std::string const & value ) const {
    try
    {
        float i = std::stof(value);
        if (std::numeric_limits<float>::max() < i || i < std::numeric_limits<float>::lowest())
            throw notFloat();
        return new Operand<float>(value, Float);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
IOperand const * Factory::createDouble( std::string const & value ) const {
    try
    {
        double i = std::stod(value);
        if (std::numeric_limits<double>::max() < i || i < std::numeric_limits<double>::lowest())
            throw notDouble();
        return new Operand<double>(value, Double);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{
	if (type == Int8)
		return createInt8(value);
	else if (type == Int16)
		return createInt16(value);
	else if (type == Int32)
		return createInt32(value);
	else if (type == Float)
		return createFloat(value);
	else if (type == Double)
		return createDouble(value);
	return 0;
}

Factory::Factory(Factory const & rhs)
{
	*this = rhs;
	return ;
}

Factory			&Factory::operator=( Factory const &rhs)
{
	if(this != &rhs)
		return *this;
	return *this;
}