#include "SuperMutant.hpp"

/*
	Constructors and destructors
*/

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &inst)
{
	*this = inst;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}


/*
	Operator overloads
*/

SuperMutant &	SuperMutant::operator=(SuperMutant const &rightOp)
{
	this->_hp = rightOp._hp;
	this->_type = rightOp._type;

	return *this;
}


/*
	Member functions
*/

void			SuperMutant::takeDamage(int dmg)
{
	dmg -= 3;
	
	if (dmg < 0)
		return ;

	this->_hp -= dmg;
}