#include "ScavTrap.hpp"

/*
	Constructors and destructors
*/

ScavTrap::ScavTrap()
{
	this->_initScav();

	std::cout << "Hey everybody! Check out my package!" << std::endl;
	std::cout << "My name is " << this->_name << ", and I'm a SC4V-TP model !" << std::endl;

	return ;
}

ScavTrap::ScavTrap(std::string const &name) 
{
	this->_initScav();
	this->_name = name;

	std::cout << "Hey everybody! Check out my package!" << std::endl;
	std::cout << "My name is " << this->_name << ", and I'm a SC4V-TP model !" << std::endl;

	return ;
}

ScavTrap::ScavTrap(ScavTrap const &inst)
{	
	*this = inst;
	std::cout << "Copy completed. New SC4V-TP named " << this->_name << " ready for use." << std::endl;

	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "I'm too pretty to die!" << std::endl;

	return ;
}


/*
	Assignation operator overload
*/

ScavTrap & 	ScavTrap::operator=(ScavTrap const & rightOp)
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

void		ScavTrap::_initScav(void)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_name = "ScavTrap P. Scavtrappington";
	this->_meleeAtkDmg = 20;
	this->_rangedAtkDmg = 15;
	this->_armorDmgReduction = 3;
}

void		ScavTrap::challengeNewcomer(void)
{
	std::string challenges[5] = 
	{
		"You versus me ! Me versus you ! Either way !",
		"I will prove to you my robotic superiority !",
		"Dance battle ! Or, you know... regular battle.",
		"Man versus machine ! Very tiny streamlined machine !",
		"Care to have a friendly duel ?"
	};

	std::cout << "I, the Mighty " << this->_name << " will challenge you !" << std::endl;
	std::cout << challenges[rand() % 5] << std::endl;

	return ;
}
