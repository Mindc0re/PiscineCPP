#include "mutantstack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    std::cout << "MutantStack is " << (mstack.empty() ? "empty" : "not empty") << std::endl;

    mstack.push(5);
    mstack.push(17);

    std::cout << "MutantStack is " << (mstack.empty() ? "empty" : "not empty") << std::endl; 

    std::cout << "Top : " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size : " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    return 0;
}