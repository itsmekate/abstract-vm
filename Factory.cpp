#include "Factory.hpp"
#include "Exception.hpp"
#include "Operand.hpp"

Factory::Factory(){}
Factory::~Factory(){}

IOperand const * Factory::createInt8( std::string const & value ) const {
	try
	{
//		int i = std::stoi(value);
//		if (std::numeric_limits<char>::biggest() > i || i < std::numeric_limits<char>::lowest())
//			throw notInt8();
		return new Operand<char>(value, Int8, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}


}
IOperand const * Factory::createInt16( std::string const & value ) const {
	 if (!stoi(value))
		throw notInt16::what();
	return new Operand<short>(value, Int16, 0);
}
IOperand const * Factory::createInt32( std::string const & value ) const {
	 if (!stoi(value))
		throw notInt32::what();
	return new Operand<int>(value, Int32, 0);
}
IOperand const * Factory::createFloat( std::string const & value ) const {
	 if (!stof(value))
		 throw notFloat::what();
	return new Operand<float>(value, Float);
}
IOperand const * Factory::createDouble( std::string const & value ) const {
	 if (!stod(value))
		 throw notDouble::what();
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