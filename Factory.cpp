#include "Factory.hpp"

IOperand const * Factory::createInt8( std::string const & value ) const {
	return new Int8(value);
}
IOperand const * Factory::createInt16( std::string const & value ) const {
	return new Int16(value);
}
IOperand const * Factory::createInt32( std::string const & value ) const {
	return new Int32(value);
}
IOperand const * Factory::createFloat( std::string const & value ) const {
	return new Float(value);
}
IOperand const * Factory::createDouble( std::string const & value ) const {
	return new Double(value);
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
}