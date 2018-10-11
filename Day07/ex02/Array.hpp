#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>

template<typename T>
class Array
{

public:
    Array<T>() : _size(0)
    {
        this->_array = new T[0];
    }

    Array<T>(unsigned int n) : _size(n)
    {
        this->_array = new T[n];
    }

    Array<T>(Array<T> const &inst)
    {
        _array = new T[inst.size()];
        _size = inst.size();

        for (int i = 0 ; i < _size ; i++)
            _array[i] = inst._array[i];
    }

    Array<T> &     operator=(Array<T> const &rhs)
    {
        delete _array;
        _array = new T[rhs.size()];
        _size = rhs.size();

        for (int i = 0 ; i < _size ; i++)
            _array[i] = rhs._array[i];

        return *this;
    }

    T &     operator[](int i)
    {
        if (i >= _size)
            throw std::exception();
        
        return _array[i];
    }

    int     size(void) const
    {
        return _size;
    }

private:
    T * _array;
    int _size;

};

#endif