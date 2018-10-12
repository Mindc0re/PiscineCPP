#include "InputVal.hpp"

InputVal::InputVal() { }

InputVal::InputVal(InputVal const &inst) { *this = inst; }

InputVal::~InputVal() { }

InputVal &  InputVal::operator=(InputVal const &rhs) { (void)rhs; return *this; }

void               InputVal::execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index)
{
    std::cin >> *(*(ptr));
    (void)index;
    (void)instList;
}