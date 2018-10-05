#include "FragTrap.hpp"

/*
	Constructors and destructors
*/

FragTrap::FragTrap()
{
	this->_initClap();

	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	std::cout << "My name is " << this->_name << ", and I'm a FR4G-TP model !" << std::endl;

	return ;
}

FragTrap::FragTrap(std::string const &name)
{
	this->_initClap();
	this->_name = name;

	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	std::cout << "My name is " << this->_name << ", and I'm a FR4G-TP model !" << std::endl;

	return ;
}

FragTrap::FragTrap(FragTrap const &inst)
{	
	*this = inst;
	std::cout << "I'm a copy of another FragTrap...? This time it'll be awesome, I promise !" << std::endl;
	
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;

	return ;
}


/*
	Assignation operator overload
*/

FragTrap & 	FragTrap::operator=(FragTrap const & rightOp)
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

void		FragTrap::_initClap(void)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_name = "FragTrap P. Fragtrappington";
	this->_meleeAtkDmg = 30;
	this->_rangedAtkDmg = 20;
	this->_armorDmgReduction = 5;
}

void		FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << "This is the typical ranged attack of a FragTrap. "
			  << this->_name << " dealt " << this->_rangedAtkDmg << "pts of Damage to " << target << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attacks[5] = 
	{
		"SHHHHH...TRAP --- Roses are red and/Violets are blue/Wait... how many syllables was that?",
		"MEAT UNICYCLE --- I AM ON FIRE!!! OH GOD, PUT ME OUT!!!",
		"GUN WIZARD --- You can call me Gundalf!",
		"SENSELESS SACRIFICE --- The robot is dead, long live the robot!",
		"MINION TRAP --- Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!"
	};

	if (this->_energyPoints < 25)
	{
		std::cout << this->_name << " doesn't have any energy points left..." << std::endl;
		std::cout << "Times like these, I really start to question the meaning of my existence. Then I get distra-hey! What's this? This looks cool!" << std::endl;
		return ;
	}

	this->_energyPoints -= 25;

	std::cout << "Recompiling my combat code... I have " << this->_energyPoints << " energy points left ! " << std::endl;
	int atk = rand() % 5;
	std::cout << attacks[atk] << std::endl;
	if (atk == 0)
		std::cout << this->_name << " killed " << target << " with confusion." << std::endl;
	else if (atk == 1)
		std::cout << this->_name << " killed " << target << " by immolating both of them." << std::endl;
	else if (atk == 2)
		std::cout << this->_name << " Avada Kedavraed " << target << std::endl;
	else if (atk == 3)
		std::cout << this->_name << " killed " << target << " by commiting seppuku and exploding." << std::endl;
	else if (atk == 4)
		std::cout << this->_name << " killed " << target << " by... well... shooting a lot I think ?" << std::endl;

	return ;
}
