#include <iostream>

template<typename T, typename U>
void    iter(T arr[], int length, U (*f)(T &))
{
    for (int i = 0 ; i < length ; i++)
        f(arr[i]);

    return ;
}

template<typename T>
void myPrint( T & val ) { std::cout << val << std::endl; }

int    ft_strlen(char * &s)
{
    int myLength = 0;

    while (s[myLength])
        myLength++;

    std::cout << "myLength of " << s << " = " << myLength << std::endl;

    return myLength;
}

void addOne(int &n) { n += 1; }

int main(int ac, char **av)
{
    int tab[] = {0, 1, 2, 3, 4};

    for (int i = 0 ; i < 5 ; i++) { std::cout << tab[i] << std::endl; }
    iter<int, void>(tab, 5, addOne);
    for (int i = 0 ; i < 5 ; i++) { std::cout << tab[i] << std::endl; }

    std::cout << std::endl;

    iter<int, void>(tab, 5, myPrint);

    std::cout << std::endl;

    iter<char *, int>(av, ac, ft_strlen);
    iter<char *, void>(av, ac, myPrint);

    return 0;
}
