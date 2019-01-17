#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
#include "Factory.hpp"
#include "Exception.hpp"

template <typename T>

class Operand : public IOperand
{
	public:
		Operand(std::string v, eOperandType Tp, int P) : Type(Tp), value(v), Precision(P){}
		Operand(std::string v, eOperandType Tp) : Type(Tp), value(v){
			setPrecision();
		}
		~Operand(){}

		void	setPrecision()
		{
			size_t point = value.find('.');
			if (point >= 0 && point < value.length())
				Precision = value.length() - point - 1;
			else
				Precision = 0;
		}

		std::string const & toString( void ) const {
			return value;
		}
		int getPrecision( void ) const {
			return Precision;
		}
		eOperandType getType( void ) const {
			return Type;
		}

		IOperand const * operator+( IOperand const & rhs ) const {
			try {
				double res = stod(value) + stod(rhs.toString());
				eOperandType t = (rhs.getType() >= this->getType()) ? rhs.getType() : this->getType();
				return Factory().createOperand(t, std::to_string(res));
			}
			catch (std::exception &e) {
				std::cout << e.what() << '\n';
			}
			return 0;
		}
		IOperand const * operator-( IOperand const & rhs ) const{
			try
			{
				double res = stod(value) - stod(rhs.toString());
				eOperandType t = (rhs.getType() >= this->getType()) ? rhs.getType() : this->getType();
				return Factory().createOperand(t, std::to_string(res));
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
			return 0;
		}
		IOperand const * operator*( IOperand const & rhs ) const{
			try
			{
				double res = stod(value) * stod(rhs.toString());
				eOperandType t = (rhs.getType() >= this->getType()) ? rhs.getType() : this->getType();
				return Factory().createOperand(t, std::to_string(res));
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
			return 0;
		}
		IOperand const * operator/( IOperand const & rhs ) const{
			try
			{
				if (stod(rhs.toString()) == 0)
					throw divisionByZero();
				double res =  stod(value) / stod(rhs.toString());
				eOperandType t = (rhs.getType() >= this->getType()) ? rhs.getType() : this->getType();
				return Factory().createOperand(t, std::to_string(res));
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
			return 0;
		}
		IOperand const * operator%( IOperand const & rhs ) const{
			try
			{
				if (stod(rhs.toString()) == 0)
					throw divisionByZero();
				double res = stoi(value) % stoi(rhs.toString());
				eOperandType t = (rhs.getType() >= this->getType()) ? rhs.getType() : this->getType();
				return Factory().createOperand(t, std::to_string(res));
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
			return 0;
		}

	private:
		eOperandType	Type;
		std::string		value;
		int				Precision;
};



#endif