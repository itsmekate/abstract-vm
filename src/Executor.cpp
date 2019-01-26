#include "../inc/Executor.hpp"

Executor::Executor(){
    try {
        Lexer l = Lexer();
        l.readFromStdin();
        if (!l.getErrors().empty())
            throw lexicalError();
        Parser(l.getFile());
        process_file(l.getFile());
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

Executor::Executor(char *file){
    try {
        Lexer l = Lexer();
        l.readFromFile(file);
        if (!l.getErrors().empty())
            throw lexicalError();
        Parser(l.getFile());
        process_file(l.getFile());
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

Executor::~Executor()
{
    if (!(stack.empty()))
    {
        for (const auto & vec : stack) {
            delete vec;
        }
    }
}

Executor::Executor(Executor const & rhs){
    *this = rhs;
}
Executor			&Executor::operator=( Executor const &rhs){
    if (this != &rhs)
        this->stack = rhs.stack;
    return (*this);
}

eOperandType Executor::getOperandType(std::string type)
{
    eOperandType T = Int8;
    if (type == "int16")
        T = Int16;
    else if (type == "int32")
        T = Int32;
    else if (type == "float")
        T =Float;
    else if (type == "double")
        T = Double;
    return T;
}

void Executor::process_file(std::vector<std::map<std::string, std::string>> file)
{
    for(auto &i : file){
        if (i["cmd"] == "exit")
            return ;
        else if (i["cmd"] == "push")
            Push(i["value"], getOperandType(i["type"]));
        else if (i["cmd"] == "assert")
            Assert(i["value"], getOperandType(i["type"]));
        else if (i["cmd"] == "pop")
            Pop();
        else if (i["cmd"] == "dump")
            Dump();
        else if (i["cmd"] == "add")
            Add();
        else if (i["cmd"] == "sub")
            Sub();
        else if (i["cmd"] == "mul")
            Mul();
        else if (i["cmd"] == "div")
            Div();
        else if (i["cmd"] == "mod")
            Mod();
        else if (i["cmd"] == "print")
            Print();
    }
}

void Executor::Push(std::string value, eOperandType type){
    IOperand const * a = Factory().createOperand(type, value);
    stack.push_back(a);
}

void Executor::Pop(){
    try {
        if (!(stack.empty()))
        {
            IOperand const * a = stack.back();
            stack.pop_back();
            delete a;
        }
        else
            throw stackTooSmall();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Executor::Dump(){
    try {
        if (!(stack.empty()))
        {
            for(std::vector<IOperand const *>::reverse_iterator i = stack.rbegin(); i != stack.rend(); ++i) {
                std::cout << std::setprecision((*i)->getPrecision()) << (*i)->toString() << std::endl;
            }
        }
        else
            throw stackTooSmall();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Executor::Assert(std::string value, eOperandType type){
    try {
        if (!(stack.empty()))
        {
            IOperand const * a = stack.back();
            if (value != a->toString() || type != a->getType())
                throw AssertError();
        }
        else
            throw AssertError();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Executor::Add(){
    try {
        if (stack.size() >= 2) {
            IOperand const *a = stack.back();
            stack.pop_back();
            IOperand const *b = stack.back();
            stack.pop_back();
            stack.push_back(*b + *a);
            delete a;
            delete b;
        } else
            throw stackTooSmall();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
void Executor::Sub(){
    try {
        if (stack.size() >= 2)
        {
            IOperand const * a = stack.back();
            stack.pop_back();
            IOperand const * b = stack.back();
            stack.pop_back();
            stack.push_back(*b - *a);
            delete a;
            delete b;
        }
        else
            throw stackTooSmall();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
void Executor::Mul(){
    try {
        if (stack.size() >= 2)
        {
            IOperand const * a = stack.back();
            stack.pop_back();
            IOperand const * b = stack.back();
            stack.pop_back();
            stack.push_back(*b * *a);
            delete a;
            delete b;
        }
        else
            throw stackTooSmall();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
void Executor::Div(){
    try {
        if (stack.size() >= 2)
        {
            IOperand const * a = stack.back();
            stack.pop_back();
            IOperand const * b = stack.back();
            stack.pop_back();
            stack.push_back(*b / *a);
            delete a;
            delete b;
        }
        else
            throw stackTooSmall();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
void Executor::Mod(){
    try {
        if (stack.size() >= 2)
        {
            IOperand const * a = stack.back();
            stack.pop_back();
            IOperand const * b = stack.back();
            stack.pop_back();
            stack.push_back(*b % *a);
            delete a;
            delete b;
        }
        else
            throw stackTooSmall();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Executor::Print(){
    try {
        if (!stack.empty())
        {
            IOperand const * a = stack.back();
            if (a->getType() == Int8)
                std::cout << (char)(stoi(a->toString())) << std::endl;
            else
                throw AssertError();
        }
        else
            throw stackTooSmall();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}