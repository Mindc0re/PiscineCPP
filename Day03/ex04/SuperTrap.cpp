#include "SuperTrap.hpp"

/*
	Constructors and destructors
*/

SuperTrap::SuperTrap() : ClapTrap(), FragTrap(), NinjaTrap()
{
	this->_initClap();

	std::cout << "SuperTrap. Named " << this->_name  << "." << std::endl;

	return ;
}

SuperTrap::SuperTrap(std::string const &name) : ClapTrap(), FragTrap(), NinjaTrap()
{
	this->_initClap();
	this->_name = name;


	std::cout << "SuperTrap. Named" << this->_name  << "." << std::endl;

	return ;
}

SuperTrap::SuperTrap(SuperTrap const &inst)
{	
	*this = inst;
	std::cout << "New SuperTrap created by copy. Lovely isn't it ?" << std::endl;
	
	return ;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SuperTrap died. Boo hoo." << std::endl;

	return ;
}


/*
	Assignation operator overload
*/

SuperTrap & 	SuperTrap::operator=(SuperTrap const & rightOp)
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

void		SuperTrap::_initClap(void)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_name = "SuperTrap P. Supertrappington";
	this->_meleeAtkDmg = 60;
	this->_rangedAtkDmg = 20;
	this->_armorDmgReduction = 5;
}

void		SuperTrap::rangedAttack(std::string const & target) const
{
	FragTrap::rangedAttack(target);
}

void		SuperTrap::meleeAttack(std::string const & target) const
{
	NinjaTrap::meleeAttack(target);
}









// void		SuperTrap::ninjaShoebox(ClapTrap &clap)
// {
// 	std::cout << "SuperTrap versus ClapTrap..." << std::endl;
// 	clap.takeDamage(60);
// 	clap.takeDamage(60);
// 	std::cout << "ClapTrap was no match for the Legendary SuperTrap..." << std::endl;
// }

// void		SuperTrap::ninjaShoebox(FragTrap &clap)
// {
// 	std::cout << "SuperTrap versus FragTrap..." << std::endl;
// 	clap.takeDamage(50);
// 	this->takeDamage(20);
// 	std::cout << "This was a good fight, but the Legendary SuperTrap is better and faster than the FragTrap..." << std::endl;
// }

// void		SuperTrap::ninjaShoebox(ScavTrap &clap)
// {
// 	std::cout << "SuperTrap versus ScavTrap..." << std::endl;
// 	clap.takeDamage(10002);
// 	this->beRepaired(9999);
// 	std::cout << "SuperTrap was so fast he decimated the ScavTrap and repaired himself with the pieces of his defeated oponent." << std::endl;
// }

// void		SuperTrap::ninjaShoebox(SuperTrap &clap)
// {
// 	std::cout << "SuperTrap versus SuperTrap... Wait what ? WHAT ? NO ! NO !!! DON'T DO THAT !!!" << std::endl;
// 	this->takeDamage(9999);
// 	clap.takeDamage(9999);
// 	std::cout << "The two SuperTraps killed each other at the same exact moment with a single killing blow, proving their mighty power." << std::endl;
// }