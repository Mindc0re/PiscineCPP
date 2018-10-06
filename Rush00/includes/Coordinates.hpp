#ifndef COORDINATES_HPP
# define COORDINATES_HPP

class Coordinates
{

public:

	Coordinates();
	Coordinates(int x, int y);
	Coordinates(Coordinates const &inst);
	~Coordinates();

	Coordinates &	operator=(Coordinates const &rhs);
	bool			operator==(Coordinates const &rhs) const;

	int 		x;
	int			y;

};

#endif