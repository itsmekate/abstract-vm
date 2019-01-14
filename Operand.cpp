#include "Operand.hpp"

Operand::Operand(eOperandType l, eOperandType r) : left(l), right(r){}
Operand::~Operand(){}

template <typename Type> type Operand<eOperandType>::operator+(Operand const & rhs)
{
  return rhs.left + rhs.right;
}