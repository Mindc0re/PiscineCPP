#ifndef ENDLOOP_HPP
# define ENDLOOP_HPP

# include "IInstruction.hpp"

class BeginLoop;

class   EndLoop : public IInstruction
{
public:
    EndLoop();
    EndLoop(EndLoop const &inst);
    virtual ~EndLoop();

    EndLoop &  operator=(EndLoop const &rhs);

    virtual void                execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index);
};

#endif