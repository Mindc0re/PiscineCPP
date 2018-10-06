#include "PlasmaRifle.hpp"

/*
	Constructors and destructors
*/

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{

}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &inst)
{
	*this = inst;
}

PlasmaRifle::~PlasmaRifle()
{

}


/*
	Operator overloads
*/

PlasmaRifle &		PlasmaRifle::operator=(PlasmaRifle const &rightOp)
{
	this->_name = rightOp._name;
	this->_apCost = rightOp._apCost;
	this->_damage = rightOp._damage;

	return *this;
}


/*
	Member functions
*/

void				PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}