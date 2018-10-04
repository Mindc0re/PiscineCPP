#include "Fixed.class.hpp"

int main( void ) 
{
	Fixed a( 10 );
	Fixed b( 5 );

	std::cout << a << " + " << b << " is " << a + b << std::endl;
	std::cout << a << " - " << b << " is " << a - b << std::endl;
	std::cout << a << " * " << b << " is " << a * b << std::endl;
	std::cout << a << " / " << b << " is " << a / b << std::endl;
	
	std::cout << "a > b is " << ((a > b) ? "true !" : "false !") << std::endl;
	std::cout << "a < b is " << ((a < b) ? "true !" : "false !") << std::endl;
	std::cout << "a >= b is " << ((a >= b) ? "true !" : "false !") << std::endl;
	std::cout << "a <= b is " << ((a <= b) ? "true !" : "false !") << std::endl;
	std::cout << "a == b is " << ((a == b) ? "true !" : "false !") << std::endl;
	std::cout << "a != b is " << ((a != b) ? "true !" : "false !") << std::endl;

	std::cout << "The min between " << a << " and " << b << " is " << Fixed::min(a, b) << std::endl;
	std::cout << "The max between " << a << " and " << b << " is " << Fixed::max(a, b) << std::endl;

	std::cout << std::endl;
	a = Fixed(9);
	b = (Fixed(5.05f) * Fixed(2));

	std::cout << a << " + " << b << " is " << a + b << std::endl;
	std::cout << a << " - " << b << " is " << a - b << std::endl;
	std::cout << a << " * " << b << " is " << a * b << std::endl;
	std::cout << a << " / " << b << " is " << a / b << std::endl;

	std::cout << "a > b is " << ((a > b) ? "true !" : "false !") << std::endl;
	std::cout << "a < b is " << ((a < b) ? "true !" : "false !") << std::endl;
	std::cout << "a >= b is " << ((a >= b) ? "true !" : "false !") << std::endl;
	std::cout << "a <= b is " << ((a <= b) ? "true !" : "false !") << std::endl;
	std::cout << "a == b is " << ((a == b) ? "true !" : "false !") << std::endl;
	std::cout << "a != b is " << ((a != b) ? "true !" : "false !") << std::endl;

	std::cout << "The min between " << a << " and " << b << " is " << Fixed::min(a, b) << std::endl;
	std::cout << "The max between " << a << " and " << b << " is " << Fixed::max(a, b) << std::endl;

	std::cout << std::endl;
	a = Fixed(0);
	b = Fixed(0);

	std::cout << a << " + " << b << " is " << a + b << std::endl;
	std::cout << a << " - " << b << " is " << a - b << std::endl;
	std::cout << a << " * " << b << " is " << a * b << std::endl;
	std::cout << a << " / " << b << " is " << a / b << std::endl;

	std::cout << "a > b is " << ((a > b) ? "true !" : "false !") << std::endl;
	std::cout << "a < b is " << ((a < b) ? "true !" : "false !") << std::endl;
	std::cout << "a >= b is " << ((a >= b) ? "true !" : "false !") << std::endl;
	std::cout << "a <= b is " << ((a <= b) ? "true !" : "false !") << std::endl;
	std::cout << "a == b is " << ((a == b) ? "true !" : "false !") << std::endl;
	std::cout << "a != b is " << ((a != b) ? "true !" : "false !") << std::endl;

	std::cout << "The min between " << a << " and " << b << " is " << Fixed::min(a, b) << std::endl;
	std::cout << "The max between " << a << " and " << b << " is " << Fixed::max(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << --b << std::endl;
	std::cout << b << std::endl;
	std::cout << b-- << std::endl;
	std::cout << b << std::endl;

	Fixed const aC( 10 );
	Fixed const bC( 5 );

	std::cout << "The min between consts " << aC << " and " << bC << " is " << Fixed::min(aC, bC) << std::endl;
	std::cout << "The max between consts " << aC << " and " << bC << " is " << Fixed::max(aC, bC) << std::endl;

	return 0;
}