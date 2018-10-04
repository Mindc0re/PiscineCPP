#include "Fixed.class.hpp"

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed(Fixed const & inst)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = inst;

	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

	return ;
}

Fixed & 	Fixed::operator=(Fixed const & rightOp)
{
	std::cout << "Assignation operator called" << std::endl;

	this->_n = rightOp.getRawBits();

	return *this;
}

int 		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->_n;
}

void		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_n = raw;

	return ;
}

int const	Fixed::_fractBits = 8;