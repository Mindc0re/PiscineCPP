#ifndef OUTPUTVAL_HPP
# define OUTPUTVAL_HPP

# include "IInstruction.hpp"

class   OutputVal : public IInstruction
{
public:
    OutputVal();
    OutputVal(OutputVal const &inst);
    virtual ~OutputVal();

    OutputVal &  operator=(OutputVal const &rhs);

    virtual void                execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index);
};

#endif