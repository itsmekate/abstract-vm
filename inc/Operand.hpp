#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "../inc/IOperand.hpp"
#include "../inc/Factory.hpp"
#include "../inc/Exception.hpp"
#include "../inc/Parser.hpp"
template <typename T>

class Operand : public IOperand
{
	public:
		Operand(std::string v, eOperandType Tp, int P) : Type(Tp), value(v), Precision(P){}
		Operand(std::string v, eOperandType Tp) : Type(Tp), value(v){
			setPrecision();
		}
		~Operand(){}
        Operand(Operand const & rhs){
			*this = rhs;
		}
        Operand			&operator=( Operand const &rhs){
			if (rhs != this)
			{
				this->value = rhs.value;
				this->Precision = rhs.Precision;
				this->Type = rhs.Type;
			}
			return (*this);
		}

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

		std::string cast_result(double res, eOperandType t) const
		{
			if (t == Int8){
				Parser().checkInt8(std::to_string(res));
				signed char r = (signed char)res;
				return std::to_string(r);
			}
			else if (t == Int16){
				Parser().checkInt16(std::to_string(res));
				short r = (short)res;
				return std::to_string(r);
			}
			else if (t == Int32){
				Parser().checkInt32(std::to_string(res));
				int r = (int)res;
				return std::to_string(r);
			}
			else if (t == Float){
				Parser().checkFloat(std::to_string(res));
				float r = (float)res;
//                std::cout << "Float: " << r << std::endl;
                std::string f = std::to_string(r);
                f.erase ( f.find_last_not_of('0') + 1, std::string::npos );
				return f;
			}
			else {
				Parser().checkDouble(std::to_string(res));
				double r = res;
//				std::cout << "Double: " << r << std::endl;
                std::string f = std::to_string(r);
                f.erase ( f.find_last_not_of('0') + 1, std::string::npos );
				return f;
			}
		}

		IOperand const * operator+( IOperand const & rhs ) const {
			try {
				double res = stod(value) + stod(rhs.toString());
				eOperandType t = (rhs.getType() >= this->getType()) ? rhs.getType() : this->getType();
				return Factory().createOperand(t, cast_result(res, t));
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			return 0;
		}
		IOperand const * operator-( IOperand const & rhs ) const{
			try
			{
				double res = stod(value) - stod(rhs.toString());
				eOperandType t = (rhs.getType() >= this->getType()) ? rhs.getType() : this->getType();
				return Factory().createOperand(t, cast_result(res, t));
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			return 0;
		}
		IOperand const * operator*( IOperand const & rhs ) const{
			try
			{
				double res = stod(value) * stod(rhs.toString());
				eOperandType t = (rhs.getType() >= this->getType()) ? rhs.getType() : this->getType();
				return Factory().createOperand(t, cast_result(res, t));
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
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
				return Factory().createOperand(t, cast_result(res, t));
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
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
				return Factory().createOperand(t, cast_result(res, t));
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			return 0;
		}

	private:
		eOperandType	Type;
		std::string		value;
		int				Precision;
};


#endif