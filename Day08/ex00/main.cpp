#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    int findRet = 0;
    
    std::vector<int> vectInt;

    vectInt.push_back(21);
    vectInt.push_back(4);
    vectInt.push_back(42);
    vectInt.push_back(2);

    try
    {
        findRet = easyfind(vectInt, 4);
        std::cout << findRet << " found in vector !" << std::endl;

        findRet = easyfind(vectInt, 36);
    }    
    catch(std::exception &e)
    {
        std::cout << "36 not found !" << std::endl;
    }

    std::cout << std::endl;

    std::list<int> listInt;

    listInt.push_back(21);
    listInt.push_back(4);
    listInt.push_back(42);
    listInt.push_back(2);

    try
    {
        findRet = easyfind(listInt, 4);
        std::cout << findRet << " found in list !" << std::endl;

        findRet = easyfind(listInt, 36);
    }    
    catch(std::exception &e)
    {
        std::cout << "36 not found !" << std::endl;
    }

    std::cout << std::endl;

    std::deque<int> dequeInt;

    dequeInt.push_back(21);
    dequeInt.push_back(4);
    dequeInt.push_back(42);
    dequeInt.push_back(2);

    try
    {
        findRet = easyfind(dequeInt, 4);
        std::cout << findRet << " found in deque !" << std::endl;

        findRet = easyfind(dequeInt, 36);
    }    
    catch(std::exception &e)
    {
        std::cout << "36 not found !" << std::endl;
    }

    return 0;
}