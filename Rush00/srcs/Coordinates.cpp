#include "Coordinates.hpp"

/*
	Constructors and destructors
*/

Coordinates::Coordinates() :
x(0), y(0)
{

}

Coordinates::Coordinates(int x, int y) :
x(x), y(y)
{
	
}

Coordinates::Coordinates(Coordinates const &inst)
{
	*this = inst;
}

Coordinates::~Coordinates()
{

}


/*
	Member functions

*/

Coordinates &	Coordinates::operator=(Coordinates const &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;

	return *this;
}

bool			Coordinates::operator==(Coordinates const &rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y);
}