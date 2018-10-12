#include "BeginLoop.hpp"
#include "EndLoop.hpp"

BeginLoop::BeginLoop() { }

BeginLoop::BeginLoop(BeginLoop const &inst) { *this = inst; }

BeginLoop::~BeginLoop() { }

BeginLoop &  BeginLoop::operator=(BeginLoop const &rhs) { (void)rhs; return *this; }

void                BeginLoop::execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index)
{
    int check_boucle = 0;

    if (*(*ptr) == 0)
    {
        check_boucle = 0;
        BeginLoop *anotherBegin;
        EndLoop *end;
        while (index != instList.end())
        {
            anotherBegin = dynamic_cast<BeginLoop *>(*index);
            end = dynamic_cast<EndLoop *>(*index);
            if (anotherBegin)
                check_boucle++;
            else if (end)
            {
                if (check_boucle)
                    check_boucle--;
                if (check_boucle == 0)
                    break ;
            }
            index++;
        }
    }
}