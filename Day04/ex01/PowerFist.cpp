#include "PowerFist.hpp"

/*
	Constructors and destructors
*/

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{

}

PowerFist::PowerFist(PowerFist const &inst)
{
	*this = inst;
}

PowerFist::~PowerFist()
{

}


/*
	Operator overloads
*/

PowerFist &		PowerFist::operator=(PowerFist const &rightOp)
{
	this->_name = rightOp._name;
	this->_apCost = rightOp._apCost;
	this->_damage = rightOp._damage;

	return *this;
}


/*
	Member functions
*/

void				PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}