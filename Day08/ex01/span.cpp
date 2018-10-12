#include "span.hpp"

Span::Span() { }

Span::Span(unsigned int n) : _size(n) { }

Span::Span(Span const &inst)
{
    this->_size = inst._size;
    this->_list.erase(this->_list.begin(), this->_list.end());

    std::list<int>::const_iterator it = inst._list.begin();
    std::list<int>::const_iterator it2 = inst._list.end();
    for (; it != it2 ; it++) 
    {
        this->_list.push_back(*it);
    }
}

Span::~Span() { }

void        Span::addNumber(int n)
{
    if (_list.size() >= _size)
        throw std::exception();

    _list.push_back(n);
}

int         Span::shortestSpan()
{
    if (_list.size() <= 1)
        throw std::exception();
    
    int     span = -1;
    std::list<int>::iterator it = _list.begin();
    std::list<int>::iterator it2 = _list.begin();

    _list.sort();

    while (it2 != _list.end())
    {
        while (*it2 == *it && it2 != _list.end())
            it2++;
        if (it2 == _list.end())
            return span == -1 ? 0 : span;
        span = span == -1 ? *it2 - *it : (*it2 - *it > span ? span : *it2 - *it);
        it = it2;
    }    

    return span;
}

int         Span::longestSpan()
{
    if (_list.size() <= 1)
        throw std::exception();
    
    _list.sort();
    return *(--_list.end()) - *_list.begin();
}