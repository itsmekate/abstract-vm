#include "Operand.hpp"

int main()
{
	Factory f = Factory();
	const IOperand * o = f.createOperand(Int8, "1.2424");
	const IOperand * i = f.createOperand(Double, ".2424");
	const IOperand * p = *o + *i;
}