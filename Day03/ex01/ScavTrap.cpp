#include "ScavTrap.hpp"

/*
	Constructors and destructors
*/

ScavTrap::ScavTrap() :
_hitPoints(100), _maxHitPoints(100), _energyPoints(50), _maxEnergyPoints(50),
_level(1), _name("ScavTrap P. Scavtrappington"),
_meleeAtkDmg(20), _rangedAtkDmg(15), _armorDmgReduction(3)
{
	std::cout << "Hey everybody! Check out my package!" << std::endl;
	std::cout << "My name is " << this->_name << ", and I'm a SC4V-TP model !" << std::endl;

	return ;
}

ScavTrap::ScavTrap(std::string const &name) :
_hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100),
_level(1), _name(name),
_meleeAtkDmg(30), _rangedAtkDmg(20), _armorDmgReduction(5)
{
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

void		ScavTrap::rangedAttack(std::string const & target) const
{
	std::cout << "SC4V-TP " << this->_name << " sniped the hell out of " << target << ", causing " 
			  << this->_rangedAtkDmg << " points of damage." << std::endl;

	return ;
}

void		ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << "SC4V-TP " << this->_name << " slapped the face of " << target << ", causing " 
			  << this->_meleeAtkDmg << " points of damage." << std::endl;	
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	int realAmount = amount == 0 ? 0 : amount - this->_armorDmgReduction;
	int hpLeft = this->_hitPoints - realAmount;

	this->_hitPoints = hpLeft < 0 ? 0 : hpLeft;

	std::cout << "SC4V-TP " << this->_name << " suffered " << realAmount << " points of damage. He now has " 
			  << this->_hitPoints << " HP left" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << "You just killed a SC4V-TP. You monster." << std::endl;
	else
		std::cout << "Stop touching this SC4V-TP !" << std::endl;

	return ;
}


void		ScavTrap::beRepaired(unsigned int amount)
{
	int newHp = this->_hitPoints + amount;
	this->_hitPoints = newHp > this->_maxHitPoints ? this->_maxHitPoints : newHp;

	std::cout << "SC4V-TP " << this->_name << " was repaired. He recovered " 
			  << amount << " HP, bringing him to " << this->_hitPoints << " HP." << std::endl;

	return ;
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
