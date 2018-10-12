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

    return 0;
}