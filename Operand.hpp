#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"

template <typename Type>

class Operand : public IOperand
{
	public:
		Operand(P, S, t);
		~Operand();

		Operand const * operator+( Operand const & rhs ) {
			return stoi(rhs.value) + stoi(value);
		}
		Operand const * operator-( Operand const & rhs ){
			
		}
		Operand const * operator*( Operand const & rhs ){

		}
		Operand const * operator/( Operand const & rhs ){

		}
		Operand const * operator%( Operand const & rhs ){
			
		}

	private:
		int				Precision;
		eOperandType	Type;
		std::string		value;
};



#endif