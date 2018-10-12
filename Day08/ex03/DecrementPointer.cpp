#include "DecrementPointer.hpp"

DecrementPointer::DecrementPointer() { }

DecrementPointer::DecrementPointer(DecrementPointer const &inst) { *this = inst; }

DecrementPointer::~DecrementPointer() { }

DecrementPointer &  DecrementPointer::operator=(DecrementPointer const &rhs) { (void)rhs; return *this; }

void                DecrementPointer::execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index)
{
    --(*ptr);
    (void)index;
    (void)instList;
}