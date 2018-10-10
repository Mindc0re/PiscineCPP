#include <iostream>
#include <ctime>

class Base
{

public:
    virtual ~Base();

};

Base::~Base() {}

class A : public Base{ };
class B : public Base{ };
class C : public Base{ };

void    identify_from_pointer(Base *p)
{
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);

    if (a)
        std::cout << "A" << std::endl;
    else if (b)
        std::cout << "B" << std::endl;
    else if (c)
        std::cout << "C" << std::endl;
}

void    identify_from_reference(Base &p)
{
    try 
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(std::exception &e) {}

    try 
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch(std::exception &e) {}

    try 
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch(std::exception &e) {}
}

Base *  generate(void)
{
    Base *base;
    int randClass = rand() % 3;

    if (randClass == 0)
    {
        std::cout << "Created 'A' class" << std::endl;
        base = new A();
    }
    else if (randClass == 1)
    {
        std::cout << "Created 'B' class" << std::endl;
        base = new B();
    }
    else
    {
        std::cout << "Created 'C' class" << std::endl;
        base = new C();
    }

    return base;
}

int     main(void)
{
    srand(time(NULL));

    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);

    (void)base;

    return 0;
}