#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>() { }
    MutantStack<T>(MutantStack const &inst) 
    { 
        *this = inst; 
    }
    virtual ~MutantStack<T>() { }

    MutantStack<T> &   operator=(MutantStack<T> const &rhs)
    {
        this->_stack = rhs._stack;

        return *this;
    }  

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator    begin()
    {
        return std::stack<T>::c.begin();
    }

    iterator    end()
    {
        return std::stack<T>::c.end();
    }

private:
    std::list<T> _stack;

};

#endif