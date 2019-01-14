#include <stdio.h>
#include <unistd.h>
#include <iostream>

#include "IOperand.hpp"

int main()
{
	enum eOperandType {Int8, Int16, Int32, Float, Double};
	
	eOperandType type = Int8;
}

// #ifndef ENUM_H
// #define ENUM_H
// enum eOperandType
// {
//     Int8,
//     Int16,
//     Int32,
//     Float,
//     Double
// };
// #endif