#include "span.hpp"
#include <iostream>
#include <ctime>
#include <limits>

int main()
{
    srand(time(NULL));
    Span sp = Span(30000);

    for (int i = 0 ; i < 30000 ; i++)
    {
        sp.addNumber(rand());
    }
    std::cout << "Added 30000 numbers" << std::endl;
    try 
    {
        sp.addNumber(42);
    }
    catch (std::exception &e)
    {
        std::cout << "Could not add number because it exceeded the limits of the list" << std::endl;
    }
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}