#ifndef INPUTVAL_HPP
# define INPUTVAL_HPP

# include "IInstruction.hpp"

class   InputVal : public IInstruction
{
public:
    InputVal();
    InputVal(InputVal const &inst);
    ~InputVal();

    InputVal &  operator=(InputVal const &rhs);

    virtual void                execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index);
};

#endif