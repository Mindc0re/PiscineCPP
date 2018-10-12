#ifndef DECREMENTVAL_HPP
# define DECREMENTVAL_HPP

# include "IInstruction.hpp"

class   DecrementVal : public IInstruction
{
public:
    DecrementVal();
    DecrementVal(DecrementVal const &inst);
    virtual ~DecrementVal();

    DecrementVal &  operator=(DecrementVal const &rhs);

    virtual void                execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index);
};

#endif