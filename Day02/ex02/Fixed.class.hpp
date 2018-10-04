#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>

class Fixed
{

public:
	Fixed(void);
	Fixed(Fixed const & inst);
	Fixed(const int);
	Fixed(const float);

	~Fixed(void);

	Fixed &					operator=(Fixed const & rightOp);

	Fixed 					operator+(Fixed const & rightOp) const;
	Fixed 					operator-(Fixed const & rightOp) const;
	Fixed 					operator*(Fixed const & rightOp) const;
	Fixed 					operator/(Fixed const & rightOp) const;

	bool 					operator>(Fixed const & rightOp) const;
	bool 					operator<(Fixed const & rightOp) const;
	bool 					operator>=(Fixed const & rightOp) const;
	bool 					operator<=(Fixed const & rightOp) const;
	bool 					operator==(Fixed const & rightOp) const;
	bool 					operator!=(Fixed const & rightOp) const;

	Fixed & 				operator++();
	Fixed 					operator++(int foo);
	Fixed &					operator--();
	Fixed 					operator--(int foo);	

	int 					getRawBits(void) const;
	void 					setRawBits(int const raw);
	
	int 					toInt(void) const;
	float 					toFloat(void) const;

	static Fixed &			min(Fixed & fp1, Fixed & fp2);
	static Fixed const &	min(Fixed const & fp1, Fixed const & fp2);
	static Fixed &			max(Fixed & fp1, Fixed & fp2);
	static Fixed const &	max(Fixed const & fp1, Fixed const & fp2);


private:
	int					_n;
	int static const	_fractBits;

};

std::ostream &			operator<<(std::ostream & o, Fixed const & rightOp);

#endif