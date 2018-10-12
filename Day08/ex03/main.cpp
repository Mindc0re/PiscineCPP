#include "IInstruction.hpp"
#include "BeginLoop.hpp"
#include "EndLoop.hpp"
#include "IncrementPointer.hpp"
#include "DecrementPointer.hpp"
#include "IncrementVal.hpp"
#include "DecrementVal.hpp"
#include "OutputVal.hpp"
#include "InputVal.hpp"

#include <deque>
#include <iostream>
#include <fstream>

int main()
{
    std::deque<IInstruction *> instList;

    std::ifstream myfile;
    myfile.open("tests/test1");
    if (!myfile)
    {
        std::cout << "File could not be opened" << std::endl;
        return 1;
    }

    char c;

    while (myfile >> c)
    {
        if (c == '>')
            instList.push_back(new IncrementPointer());
        else if (c == '<')
            instList.push_back(new DecrementPointer());
        else if (c == '+')
            instList.push_back(new IncrementVal());
        else if (c == '-')
            instList.push_back(new DecrementVal());
        else if (c == '.')
            instList.push_back(new OutputVal());
        else if (c == ',')
            instList.push_back(new InputVal());
        else if (c == '[')
            instList.push_back(new BeginLoop());
        else if (c == ']')
            instList.push_back(new EndLoop());
    }

    myfile.close();

    std::deque<IInstruction *>::iterator it = instList.begin();
    std::deque<IInstruction *>::iterator it2 = instList.end();

    char tab[30000] = {};
    char *ptr;

    ptr = tab;

    for (; it != it2 ; it++)
    {
        (*it)->execute(&ptr, instList, it);
    }

    return 0;
}