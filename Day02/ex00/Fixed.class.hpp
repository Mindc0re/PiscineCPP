#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{

public:
	Fixed(void);
	Fixed(Fixed const & inst);

	~Fixed(void);

	Fixed &				operator=(Fixed const & rightOp);

	int 				getRawBits(void) const;
	void 				setRawBits(int const raw);

private:
	int					_n;
	int static const	_fractBits;

};

#endif