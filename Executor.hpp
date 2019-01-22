#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <vector>
#include "IOperand.hpp"
#include "Operand.hpp"

class Executor {
    public:
        Executor();
        ~Executor();

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

    private:
    std::vector<IOperand const *> stack;
};
#endif