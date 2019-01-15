#include "Factory.hpp"

int main()
{
	Factory f = Factory();
	const IOperand * o = f.createOperand(Int8, ".2424");
	std::cout << o->getPrecision() << "\n";
}