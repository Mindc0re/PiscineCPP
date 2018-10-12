#ifndef INCREMENTPOINTER_HPP
# define INCREMENTPOINTER_HPP

# include "IInstruction.hpp"

class   IncrementPointer : public IInstruction
{
public:
    IncrementPointer();
    IncrementPointer(IncrementPointer const &inst);
    virtual ~IncrementPointer();

    IncrementPointer &  operator=(IncrementPointer const &rhs);

    virtual void                execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index);
};

#endif