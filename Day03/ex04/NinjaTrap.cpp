#include "NinjaTrap.hpp"

/*
	Constructors and destructors
*/

NinjaTrap::NinjaTrap()
{
	this->_initClap();

	std::cout << "And here is a new NinjaTrap, named " << this->_name  << " !" << std::endl;

	return ;
}

NinjaTrap::NinjaTrap(std::string const &name)
{
	this->_initClap();
	this->_name = name;

	std::cout << "And here is a new NinjaTrap, named " << this->_name  << " !" << std::endl;

	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const &inst)
{	
	*this = inst;
	std::cout << "New NinjaTrap created by copy." << std::endl;
	
	return ;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap died." << std::endl;

	return ;
}


/*
	Assignation operator overload
*/

NinjaTrap & 	NinjaTrap::operator=(NinjaTrap const & rightOp)
{
	this->_name = rightOp._name;
	this->_level = rightOp._level;
	this->_hitPoints = rightOp._hitPoints;
	this->_maxHitPoints = rightOp._maxHitPoints;
	this->_energyPoints = rightOp._energyPoints;
	this->_maxEnergyPoints = rightOp._maxEnergyPoints;
	this->_meleeAtkDmg = rightOp._meleeAtkDmg;
	this->_rangedAtkDmg = rightOp._rangedAtkDmg;
	this->_armorDmgReduction = rightOp._armorDmgReduction;

	return *this;
}


/*
	Member functions
*/

void		NinjaTrap::_initClap(void)
{
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_name = "NinjaTrap P. Ninjatrappington";
	this->_meleeAtkDmg = 60;
	this->_rangedAtkDmg = 5;
	this->_armorDmgReduction = 0;
}

void		NinjaTrap::meleeAttack(std::string const & target) const
{
	std::cout << "This is the typical melee attack of a NinjaTrap. "
			  << this->_name << " dealt " << this->_meleeAtkDmg << "pts of Damage to " << target << std::endl;
}

void		NinjaTrap::ninjaShoebox(ClapTrap &clap)
{
	std::cout << "NinjaTrap versus ClapTrap..." << std::endl;
	clap.takeDamage(60);
	clap.takeDamage(60);
	std::cout << "ClapTrap was no match for the Legendary NinjaTrap..." << std::endl;
}

void		NinjaTrap::ninjaShoebox(FragTrap &clap)
{
	std::cout << "NinjaTrap versus FragTrap..." << std::endl;
	clap.takeDamage(50);
	this->takeDamage(20);
	std::cout << "This was a good fight, but the Legendary NinjaTrap is better and faster than the FragTrap..." << std::endl;
}

void		NinjaTrap::ninjaShoebox(ScavTrap &clap)
{
	std::cout << "NinjaTrap versus ScavTrap..." << std::endl;
	clap.takeDamage(10002);
	this->beRepaired(9999);
	std::cout << "NinjaTrap was so fast he decimated the ScavTrap and repaired himself with the pieces of his defeated oponent." << std::endl;
}

void		NinjaTrap::ninjaShoebox(NinjaTrap &clap)
{
	std::cout << "NinjaTrap versus NinjaTrap... Wait what ? WHAT ? NO ! NO !!! DON'T DO THAT !!!" << std::endl;
	this->takeDamage(9999);
	clap.takeDamage(9999);
	std::cout << "The two NinjaTraps killed each other at the same exact moment with a single killing blow, proving their mighty power." << std::endl;
}
