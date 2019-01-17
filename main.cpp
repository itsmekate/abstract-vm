#include "Operand.hpp"
#include "Lexer.hpp"

int main()
{
    std::vector<std::string> file = Lexer().getFile();
    std::cout << "Here goes vector\n";
    for (std::vector<std::string>::const_iterator i = file.begin(); i != file.end(); ++i)
        std::cout << *i << ' ';
//	Factory f = Factory();
//	const IOperand * o = f.createOperand(Int8, "24");
//	const IOperand * z = f.createOperand(Double, "56");
//	const IOperand * p = *o - *z;
//	std::cout << p->toString() << "\n";
}