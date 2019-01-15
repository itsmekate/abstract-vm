#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"

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

		int	getPrecision( void ) const {
			return Precision;
		}
		/*
		Operand const * operator+( Operand const & rhs ) {
			try
			{
				double res = stod(rhs.value) + stod(value);
				// IOperand * fin = new Operand<??>(0, std::to_string(res), Int8);
			}
			catch (std::exception& e)
  			{
  			 	std::cout << e.what() << '\n';
  			}
			return fin;
		}
		Operand const * operator-( Operand const & rhs ){
			try
			{
				double res = stod(rhs.value) - stod(value);
				// Operator fin = Operator new ();
			}
			catch (exception& e)
  			{
  			 	cout << e.what() << '\n';
  			}
			return fin;
		}
		Operand const * operator*( Operand const & rhs ){
			try
			{
				double res = stod(rhs.value) * stod(value);
				// Operator fin = Operator new ();
			}
			catch (exception& e)
  			{
  			 	cout << e.what() << '\n';
  			}
			return fin;

		}
		Operand const * operator/( Operand const & rhs ){
			try
			{
				double res = stod(rhs.value) / stod(value);
				// Operator fin = Operator new ();
			}
			catch (exception& e)
  			{
  			 	cout << e.what() << '\n';
  			}
			return fin;
		}
		Operand const * operator%( Operand const & rhs ){
			try
			{
				double res = stod(rhs.value) % stod(value);
				// Operator fin = Operator new ();
			}
			catch (exception& e)
  			{
  			 	cout << e.what() << '\n';
  			}
			return fin;
		}
*/
	private:
		eOperandType	Type;
		std::string		value;
		int				Precision;
};



#endif