#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <vector>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

class Executor {
    public:
        Executor();
        Executor(char *file);
        ~Executor();
        Executor(Executor const & rhs);
        Executor			&operator=( Executor const &rhs);

        void Push(std::string value, eOperandType type);
        void Pop();
        void Dump();
        void Assert(std::string value, eOperandType type);
        void Add();
        void Sub();
        void Mul();
        void Div();
        void Mod();
        void Print();

        eOperandType getOperandType(std::string type);

        void process_file(std::vector<std::map<std::string, std::string>> file);

    private:
    std::vector<IOperand const *> stack;
};
#endif