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

    Span sp2(sp);
    std::cout << "Added 30000 numbers" << std::endl;
    try 
    {
        sp2.addNumber(42);
    }
    catch (std::exception &e)
    {
        std::cout << "Could not add number because it exceeded the limits of the list" << std::endl;
    }
    
    std::cout << "Spans of sp" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl << std::endl;

    std::cout << "Spans of sp2" << std::endl;
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
}