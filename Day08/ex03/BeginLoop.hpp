#ifndef BEGINLOOP_HPP
# define BEGINLOOP_HPP

# include "IInstruction.hpp"

class   BeginLoop : public IInstruction
{
public:
    BeginLoop();
    BeginLoop(BeginLoop const &inst);
    virtual ~BeginLoop();

    BeginLoop &  operator=(BeginLoop const &rhs);

    virtual void                execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index);
};

#endif