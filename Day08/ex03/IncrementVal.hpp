#ifndef INCREMENTVAL_HPP
# define INCREMENTVAL_HPP

# include "IInstruction.hpp"

class   IncrementVal : public IInstruction
{
public:
    IncrementVal();
    IncrementVal(IncrementVal const &inst);
    virtual ~IncrementVal();

    IncrementVal &  operator=(IncrementVal const &rhs);

    virtual void                execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index);
};

#endif