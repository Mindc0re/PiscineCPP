#ifndef SPAN_HPP
# define SPAN_HPP

# include <list>
# include <algorithm>

class Span 
{
public:
    Span(unsigned int n);
    Span(Span const &inst);
    ~Span();

    Span &  operator=(Span const &rhs);

    void    addNumber(int n);
    int     shortestSpan();
    int     longestSpan();

private:
    Span();
    
    std::list<int>  _list;
    unsigned int    _size;

};

#endif