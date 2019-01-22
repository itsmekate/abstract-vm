#include "Executor.hpp"

//    eOperandType T = Int8;
//    if (type == "Int16")
//        T = Int16;
//    else if (type == "Int32")
//        T = Int32;
//    else if (type == "Float")
//        T =Float;
//    else if (type == "Double")
//        T = Double;

Executor::Executor(){

}
Executor::~Executor(){

}

void Executor::Push(std::string value, eOperandType type){
    IOperand const * a = Factory().createOperand(type, value);
    stack.push_back(a);
    delete a;
}

void Executor::Pop(){
    if (!stack.empty())
        stack.pop_back();
    else
        throw stackTooSmall();
}

void Executor::Dump(){
    for (std::vector<IOperand const *>::const_iterator i = stack.begin(); i != stack.end(); ++i)
        std::cout << (*i)->toString() << std::endl;
}

void Executor::Assert(std::string value, eOperandType type){
    IOperand const * a = stack.back();
    if (value != a->toString() && type != a->getType())
        throw AssertError();
}

void Executor::Add(){
    if (!stack.empty() || stack.size() < 2)
    {
        IOperand const * a = stack.back();
        stack.pop_back();
        IOperand const * b = stack.back();
        stack.pop_back();
        stack.push_back(*a + *b);
        delete a;
        delete b;
    }
    else
        throw stackTooSmall();
}
void Executor::Sub(){
    if (!stack.empty() || stack.size() < 2)
    {
        IOperand const * a = stack.back();
        stack.pop_back();
        IOperand const * b = stack.back();
        stack.pop_back();
        stack.push_back(*a - *b);
        delete a;
        delete b;
    }
    else
        throw stackTooSmall();
}
void Executor::Mul(){
    if (!stack.empty() || stack.size() < 2)
    {
        IOperand const * a = stack.back();
        stack.pop_back();
        IOperand const * b = stack.back();
        stack.pop_back();
        stack.push_back(*a * *b);
        delete a;
        delete b;
    }
    else
        throw stackTooSmall();
}
void Executor::Div(){
    if (!stack.empty() || stack.size() < 2)
    {
        IOperand const * a = stack.back();
        stack.pop_back();
        IOperand const * b = stack.back();
        stack.pop_back();
        stack.push_back(*a / *b);
        delete a;
        delete b;
    }
    else
        throw stackTooSmall();
}
void Executor::Mod(){
    if (!stack.empty() || stack.size() < 2)
    {
        IOperand const * a = stack.back();
        stack.pop_back();
        IOperand const * b = stack.back();
        stack.pop_back();
        stack.push_back(*a % *b);
        delete a;
        delete b;
    }
    else
        throw stackTooSmall();
}

void Executor::Print(){
    if (!stack.empty())
    {
        IOperand const * a = stack.back();
        if (a->getType() == Int8)
            std::cout << a->toString() << std::endl;
        else
            throw AssertError();
        delete a;
    }
    else
        throw stackTooSmall();
}