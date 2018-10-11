#include "Array.hpp"

class Truc
{
public:
    Truc() : c('^') { }

    char c;
};

std::ostream &  operator<<(std::ostream &o, Truc const & rhs)
{
    o << rhs.c;
    return o;
}

int main()
{
    Array<int> a(5);
    Array<int> b;

    b = a;
    a[3] = 1;
    b[3] = 2;

    std::cout << "a[3] = " << a[3] << " and b[3] = " << b[3] << std::endl << std::endl;

    Array<int> c(a);
    a[0] = 3;
    c[0] = 4;
    std::cout << "a[0] = " << a[0] << " and c[0] = " << c[0] << std::endl << std::endl;

    try 
    {
        for (int i = 0 ; i < a.size() ; i++) { std::cout << "a[" << i << "] = " << a[i] << std::endl; }
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Array<Truc> d(3);

    try 
    {
        for (int i = 0 ; i < 4 ; i++) { std::cout << "d[" << i << "] = " << d[i] << std::endl; }
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}