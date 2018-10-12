#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

template<typename T>
int     easyfind(T const &container, int const &toFind)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
    if (it == container.end())
        throw std::exception();
    
    return *it;
}

#endif