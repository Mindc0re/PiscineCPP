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

	Fixed &				operator=(Fixed const & rightOp);

	int 				getRawBits(void) const;
	void 				setRawBits(int const raw);
	int 				toInt(void) const;
	float 				toFloat(void) const;

private:
	int					_n;
	int static const	_fractBits;

};

std::ostream &			operator<<(std::ostream & o, Fixed const & rightOp);

#endif