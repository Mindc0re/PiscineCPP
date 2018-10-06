#include "RadScorpion.hpp"

/*
	Constructors and destructors
*/

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &inst)
{
	*this = inst;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}


/*
	Operator overloads
*/

RadScorpion &	RadScorpion::operator=(RadScorpion const &rightOp)
{
	this->_hp = rightOp._hp;
	this->_type = rightOp._type;

	return *this;
}