#ifndef DECREMENTPOINTER_HPP
# define DECREMENTPOINTER_HPP

# include "IInstruction.hpp"

class   DecrementPointer : public IInstruction
{
public:
    DecrementPointer();
    DecrementPointer(DecrementPointer const &inst);
    virtual ~DecrementPointer();

    DecrementPointer &  operator=(DecrementPointer const &rhs);

    virtual void                execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index);
};

#endif