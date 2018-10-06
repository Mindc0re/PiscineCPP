#include "Character.hpp"

/*
	Constructors and destructors
*/

Character::Character()
{

}

Character::Character(std::string const &name) :
_name(name), _ap(40), _curWeapon(NULL)
{

}

Character::Character(Character const &inst)
{
	*this = inst;
}

Character::~Character()
{

}


/*
	Operator overloads
*/

Character &			Character::operator=(Character const &rightOp)
{
	this->_name = rightOp._name;
	this->_ap = rightOp._ap;
	this->_curWeapon = rightOp._curWeapon;

	return *this;
}

std::ostream &		operator<<(std::ostream &o, Character const &rightOp)
{
	std::string w = rightOp.getWeapon();

	if (w == "unarmed")
		o << rightOp.getName() << " has " << rightOp.getAP() << " AP and is unarmed" << std::endl;
	else
		o << rightOp.getName() << " has " << rightOp.getAP() << " AP and wields a " << w << std::endl;

	return o;
}


/*
	Member functions
*/

std::string 		Character::getName() const
{
	return this->_name;
}

int 				Character::getAP() const
{
	return this->_ap;
}

std::string 		Character::getWeapon() const
{
	return this->_curWeapon == NULL ? "unarmed" : this->_curWeapon->getName();
}

void				Character::recoverAP()
{
	this->_ap = this->_ap + 10 > 40 ? 40 : this->_ap + 10;
}

void				Character::equip(AWeapon *weapon)
{
	this->_curWeapon = weapon;
}

void				Character::attack(Enemy *enemy)
{
	if (this->_curWeapon == NULL || this->_ap < this->_curWeapon->getAPCost())
		return ;

	std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_curWeapon->getName() << std::endl;

	this->_curWeapon->attack();
	this->_ap -= this->_curWeapon->getAPCost();

	enemy->takeDamage(this->_curWeapon->getDamage());

	if (enemy->getHP() <= 0)
		delete(enemy);
}



