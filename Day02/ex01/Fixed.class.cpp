#include "Fixed.class.hpp"

/*
	Constructors and Destructors
*/

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

Fixed::Fixed(const int val)
{
	std::cout << "Integer constructor called" << std::endl;

	this->setRawBits(val << Fixed::_fractBits);

	return ;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;

	this->setRawBits((int)roundf(val * (1 << Fixed::_fractBits)));

	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

	return ;
}


/*
	Operator overloads
*/

Fixed & 		Fixed::operator=(Fixed const & rightOp)
{
	std::cout << "Assignation operator called" << std::endl;

	this->_n = rightOp.getRawBits();

	return *this;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rightOp)
{
	o << rightOp.toFloat();

	return o;
}


/*
	Member functions
*/

int 			Fixed::getRawBits(void) const
{
	return this->_n;
}

void			Fixed::setRawBits(int const raw)
{
	this->_n = raw;

	return ;
}

int 			Fixed::toInt(void) const
{
	return this->_n >> Fixed::_fractBits;
}

float 			Fixed::toFloat(void) const
{
	return (float)this->_n / (1 << Fixed::_fractBits);
}


/*
	Static Class Variables
*/

int const		Fixed::_fractBits = 8;