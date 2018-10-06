#include "AWeapon.hpp"

/*
	Constructors and destructors
*/

AWeapon::AWeapon()
{

}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) :
_name(name), _apCost(apcost), _damage(damage)
{

}

AWeapon::AWeapon(AWeapon const &inst)
{
	*this = inst;
}

AWeapon::~AWeapon()
{

}


/*
	Operator overloads
*/

AWeapon &			AWeapon::operator=(AWeapon const &rightOp)
{
	this->_name = rightOp._name;
	this->_apCost = rightOp._apCost;
	this->_damage = rightOp._damage;

	return *this;
}


/*
	Member functions
*/

std::string const &	AWeapon::getName() const
{
	return this->_name;
}

int 				AWeapon::getAPCost() const
{
	return this->_apCost;
}

int 				AWeapon::getDamage() const
{
	return this->_damage;
}