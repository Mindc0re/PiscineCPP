#include "OutputVal.hpp"

OutputVal::OutputVal() { }

OutputVal::OutputVal(OutputVal const &inst) { *this = inst; }

OutputVal::~OutputVal() { }

OutputVal &  OutputVal::operator=(OutputVal const &rhs) { (void)rhs; return *this; }

void               OutputVal::execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index)
{
    std::cout << *(*ptr);
    (void)index;
    (void)instList;
}