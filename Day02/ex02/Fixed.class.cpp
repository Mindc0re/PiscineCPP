#include "Fixed.class.hpp"

/*
	Constructors and Destructors
*/

Fixed::Fixed(void) : _n(0)
{
	return ;
}

Fixed::Fixed(Fixed const & inst)
{
	*this = inst;

	return ;
}

Fixed::Fixed(const int val)
{
	this->setRawBits(val << Fixed::_fractBits);

	return ;
}

Fixed::Fixed(const float val)
{
	this->setRawBits((int)roundf(val * (1 << Fixed::_fractBits)));

	return ;
}

Fixed::~Fixed(void)
{
	return ;
}


/*
	Assignation overloads
*/

Fixed & 		Fixed::operator=(Fixed const & rightOp)
{
	this->_n = rightOp.getRawBits();

	return *this;
}


/*
	Arithmetic overloads
*/

Fixed 			Fixed::operator+(Fixed const & rightOp) const
{
	return Fixed(this->toFloat() + rightOp.toFloat());
}

Fixed 			Fixed::operator-(Fixed const & rightOp) const
{
	return Fixed(this->toFloat() - rightOp.toFloat());
}

Fixed 			Fixed::operator*(Fixed const & rightOp) const
{
	return Fixed(this->toFloat() * rightOp.toFloat());
}

Fixed 			Fixed::operator/(Fixed const & rightOp) const
{
	return Fixed(this->toFloat() / rightOp.toFloat());
}

Fixed &			Fixed::operator++()
{
	this->_n++;

	return *this;
}

Fixed 			Fixed::operator++(int foo)
{
	Fixed bar(*this);
	(void)foo;
	++this->_n;
	return bar;
}

Fixed &			Fixed::operator--()
{
	this->_n--;

	return *this;
}

Fixed 			Fixed::operator--(int foo)
{
	Fixed bar(*this);
	(void)foo;
	--this->_n;
	return bar;
}


/*
	Comparison overloads
*/

bool 			Fixed::operator>(Fixed const & rightOp) const
{
	return this->toFloat() > rightOp.toFloat();
}

bool 			Fixed::operator<(Fixed const & rightOp) const
{
	return this->toFloat() < rightOp.toFloat();
}

bool 			Fixed::operator>=(Fixed const & rightOp) const
{
	return this->toFloat() >= rightOp.toFloat();
}

bool 			Fixed::operator<=(Fixed const & rightOp) const
{
	return this->toFloat() <= rightOp.toFloat();
}

bool 			Fixed::operator==(Fixed const & rightOp) const
{
	return this->toFloat() == rightOp.toFloat();
}

bool 			Fixed::operator!=(Fixed const & rightOp) const
{
	return this->toFloat() != rightOp.toFloat();
}


/*
	Stream overloads
*/

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
	Non-Member functions
*/

Fixed &			Fixed::min(Fixed & fp1, Fixed & fp2)
{
	return (fp1 > fp2) ? fp2 : fp1;
}

Fixed const &	Fixed::min(Fixed const & fp1, Fixed const & fp2)
{
	return (fp1 > fp2) ? fp2 : fp1;
}

Fixed &			Fixed::max(Fixed & fp1, Fixed & fp2)
{
	return (fp1 < fp2) ? fp2 : fp1;
}

Fixed const &	Fixed::max(Fixed const & fp1, Fixed const & fp2)
{
	return (fp1 < fp2) ? fp2 : fp1;
}

/*
	Non-Member Variables
*/

int const		Fixed::_fractBits = 8;