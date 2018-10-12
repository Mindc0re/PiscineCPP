#include "DecrementVal.hpp"

DecrementVal::DecrementVal() { }

DecrementVal::DecrementVal(DecrementVal const &inst) { *this = inst; }

DecrementVal::~DecrementVal() { }

DecrementVal &  DecrementVal::operator=(DecrementVal const &rhs) { (void)rhs; return *this; }

void               DecrementVal::execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index)
{
    --**ptr;
    (void)index;
    (void)instList;
}