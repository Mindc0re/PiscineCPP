#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

# include <deque>
# include <iostream>

class IInstruction
{
public:
    virtual ~IInstruction() {};

    virtual void execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index) = 0;
};

#endif