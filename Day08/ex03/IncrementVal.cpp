#include "IncrementVal.hpp"

IncrementVal::IncrementVal() { }

IncrementVal::IncrementVal(IncrementVal const &inst) { *this = inst; }

IncrementVal::~IncrementVal() { }

IncrementVal &  IncrementVal::operator=(IncrementVal const &rhs) { (void)rhs; return *this; }

void               IncrementVal::execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index)
{
    ++**ptr;
    (void)index;
    (void)instList;
}