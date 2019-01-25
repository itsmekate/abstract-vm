#include "../inc/Factory.hpp"
#include "../inc/Exception.hpp"
#include "../inc/Operand.hpp"
#include<limits.h>

Factory::Factory(){}
Factory::~Factory(){}

IOperand const * Factory::createInt8( std::string const & value ) const {
    return new Operand<signed char>(value, Int8, 0);
}
IOperand const * Factory::createInt16( std::string const & value ) const {
    return new Operand<short>(value, Int16, 0);
}
IOperand const * Factory::createInt32( std::string const & value ) const {
    return new Operand<int>(value, Int32, 0);
}
IOperand const * Factory::createFloat( std::string const & value ) const {
    return new Operand<float>(value, Float);
}
IOperand const * Factory::createDouble( std::string const & value ) const {
    return new Operand<double>(value, Double);
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