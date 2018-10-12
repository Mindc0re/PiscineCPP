#include "BeginLoop.hpp"
#include "EndLoop.hpp"

EndLoop::EndLoop() { }

EndLoop::EndLoop(EndLoop const &inst) { *this = inst; }

EndLoop::~EndLoop() { }

EndLoop &  EndLoop::operator=(EndLoop const &rhs) { (void)rhs; return *this; }

void                EndLoop::execute(char **ptr, std::deque<IInstruction *> instList, std::deque<IInstruction *>::iterator &index)
{
    int check_boucle = 0;

    if (*(*ptr) != 0)
    {
        check_boucle = 0;
        BeginLoop *begin;
        EndLoop *anotherEnd;
        while (index != instList.begin())
        {
            begin = dynamic_cast<BeginLoop *>(*index);
            anotherEnd = dynamic_cast<EndLoop *>(*index);
            if (anotherEnd)
                check_boucle++;
            else if (begin)
            {
                if (check_boucle)
                    check_boucle--;
                if (check_boucle == 0)
                    break ;
            }
            index--;
        }
    }
}