#include "FragTrap.hpp"

/*
	Constructors and destructors
*/

FragTrap::FragTrap() :
_hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100),
_level(1), _name("FragTrap P. Fragtrappington"),
_meleeAtkDmg(30), _rangedAtkDmg(20), _armorDmgReduction(5)
{
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	std::cout << "My name is " << this->_name << ", and I'm a FR4G-TP model !" << std::endl;

	return ;
}

FragTrap::FragTrap(std::string const &name) :
_hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100),
_level(1), _name(name),
_meleeAtkDmg(30), _rangedAtkDmg(20), _armorDmgReduction(5)
{
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

void		FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " 
			  << this->_rangedAtkDmg << " points of damage... Sniped!" << std::endl;

	return ;
}

void		FragTrap::meleeAttack(std::string const & target) const
{
	std::cout << "Ready for the PUNCHline? FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " 
			  << this->_meleeAtkDmg << " points of damage." << std::endl;	
}

void		FragTrap::takeDamage(unsigned int amount)
{
	int realAmount = amount == 0 ? 0 : amount - this->_armorDmgReduction;
	int hpLeft = this->_hitPoints - realAmount;

	this->_hitPoints = hpLeft < 0 ? 0 : hpLeft;

	std::cout << "FR4G-TP " << this->_name << " suffered " << realAmount << " points of damage. He has been left with " 
			  << this->_hitPoints << " HP" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << "YES !! YOU KILLED HIM !! Congrats, you made the world a better place." << std::endl;
	else
		std::cout << "Please kill him quick..." << std::endl;

	return ;
}


void		FragTrap::beRepaired(unsigned int amount)
{
	int newHp = this->_hitPoints + amount;
	this->_hitPoints = newHp > this->_maxHitPoints ? this->_maxHitPoints : newHp;

	std::cout << "FR4G-TP " << this->_name << " was... repaired...? Why would anyone even do that ?!! Whatever, he recovered " 
			  << amount << " HP, bringing him to " << this->_hitPoints << " HP..." << std::endl;

	return ;
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
