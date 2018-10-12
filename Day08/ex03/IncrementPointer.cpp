#include "IncrementPointer.hpp"

IncrementPointer::IncrementPointer() { }

IncrementPointer::IncrementPointer(IncrementPointer const &inst) { *this = inst; }

IncrementPointer::~IncrementPointer() { }

IncrementPointer &  IncrementPointer::operator=(IncrementPointer const &rhs) { (void)rhs; return *this; }

void               IncrementPointer::execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index)
{
    ++(*ptr);
    (void)index;
    (void)instList;
}