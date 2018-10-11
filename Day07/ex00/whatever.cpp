#include <iostream>

class Whatever {

public:

Whatever(int n) : _n(n) {}

    bool operator==(Whatever const & rhs) const { return (this->_n == rhs._n); }
    bool operator!=(Whatever const & rhs) const { return (this->_n != rhs._n); }
    bool operator>(Whatever const & rhs) const { return (this->_n > rhs._n); }
    bool operator<(Whatever const & rhs) const { return (this->_n < rhs._n); }
    bool operator>=(Whatever const & rhs) const { return (this->_n >= rhs._n); }
    bool operator<=(Whatever const & rhs) const { return (this->_n <= rhs._n); }

    Whatever &  operator=(Whatever const & rhs) { this->_n = rhs._n; return *this; }

    int getN() const { return this->_n; }

private:

    Whatever(void) {}

    int _n;

};


template<typename T>
void        swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T const &   min(T const &a, T const &b)
{
    return (b <= a ? b : a);
}

template<typename T>
T const &   max(T const &a, T const &b)
{
    return (b >= a ? b : a);
}

int main(void)
{
    int a = 1;
    int b = 2;
    int c = 2;

    int minRet = ::min(a, b);
    std::cout << minRet << " is the smallest of " << a << " and " << b << std::endl;
    minRet = ::min(b, c);
    std::cout << minRet << " is the smallest of " << b << " and " << c << std::endl;

    int maxRet = ::max(a, b);
    std::cout << maxRet << " is the biggest of " << a << " and " << b << std::endl;
    maxRet = ::max(b, c);
    std::cout << maxRet << " is the biggest of " << b << " and " << c << std::endl;

    ::swap(a, b);
    std::cout << "a = " << a << " and b = " << b << std::endl;


    std::cout << std::endl;


    std::string sA = "chaine1";
    std::string sB = "chaine2";
    std::string sC = "chaine2";

    std::string sMinRet = ::min(sA, sB);
    std::cout << sMinRet << " is the smallest of " << sA << " and " << sB << std::endl;
    sMinRet = ::min(sB, sC);
    std::cout << sMinRet << " is the smallest of " << sB << " and " << sC << std::endl;

    std::string sMaxRet = ::max(sA, sB);
    std::cout << sMaxRet << " is the biggest of " << sA << " and " << sB << std::endl;
    sMaxRet = ::max(sB, sC);
    std::cout << sMaxRet << " is the biggest of " << sB << " and " << sC << std::endl;

    ::swap(sA, sB);
    std::cout << "sA = " << sA << " and sB = " << sB << std::endl;


    std::cout << std::endl;


    Whatever whatever1(1);
    Whatever whatever2(2);
    Whatever whatever3(2);

    Whatever whatMinRet = ::min(whatever1, whatever2);
    std::cout << whatMinRet.getN() << " is the smallest of " << whatever1.getN() << " and " << whatever2.getN() << std::endl;
    whatMinRet = ::min(whatever2, whatever3);
    std::cout << whatMinRet.getN() << " is the smallest of " << whatever2.getN() << " and " << whatever3.getN() << std::endl;

    Whatever whatMaxRet = ::max(whatever1, whatever2);
    std::cout << whatMaxRet.getN() << " is the biggest of " << whatever1.getN() << " and " << whatever2.getN() << std::endl;
    whatMaxRet = ::max(whatever2, whatever3);
    std::cout << whatMaxRet.getN() << " is the biggest of " << whatever2.getN() << " and " << whatever3.getN() << std::endl;

    std::cout << "whatever1 = " << whatever1.getN() << " and whatever2 = " << whatever2.getN() << std::endl;
    swap(whatever1, whatever2);
    std::cout << "whatever1 = " << whatever1.getN() << " and whatever2 = " << whatever2.getN() << std::endl;

    return 0;
}