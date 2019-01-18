#include "Operand.hpp"
#include "Lexer.hpp"

int main(int argc, char **argv)
{
    std::vector<std::string> file;
    Lexer l = Lexer();
    if (argc == 2)
        l.readFromFile(argv[1]);
    else
        l.readFromStdin();
    file = l.getFile();
    std::cout << "Here goes vector\n";
    for (std::vector<std::string>::const_iterator i = file.begin(); i != file.end(); ++i)
        std::cout << *i << std::endl;
//	Factory f = Factory();
//	const IOperand * o = f.createOperand(Int8, "24");
//	const IOperand * z = f.createOperand(Double, "56");
//	const IOperand * p = *o - *z;
//	std::cout << p->toString() << "\n";
}