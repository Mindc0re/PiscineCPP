#include "ClapTrap.hpp"

/*
	Constructors and destructors
*/

ClapTrap::ClapTrap(void) :
_hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100),
_level(1), _name("ClapTrap P. Claptrappington"),
_meleeAtkDmg(30), _rangedAtkDmg(20), _armorDmgReduction(5)
{
	std::cout << "A new ClapTrap unit was created !" << std::endl;

	return ;
}

ClapTrap::ClapTrap(std::string const &name) :
_hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100),
_level(1), _name(name),
_meleeAtkDmg(30), _rangedAtkDmg(20), _armorDmgReduction(5)
{
	std::cout << "A new ClapTrap unit was created by name ! Its name is " << this->_name << std::endl;	

	return ;
}

ClapTrap::ClapTrap(ClapTrap const &inst)
{	
	*this = inst;
	std::cout << "A new ClapTrap was created by copy of another ClapTrap. Its name is " << this->_name << std::endl;

	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "A ClapTrap unit was destroyed." << std::endl;
}


/*
	Assignation operator overload
*/

ClapTrap & 	ClapTrap::operator=(ClapTrap const & rightOp)
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

void		ClapTrap::rangedAttack(std::string const & target) const
{
	std::cout << this->_name << " attacks " << target << " at range, causing " 
			  << this->_rangedAtkDmg << " points of damage... Sniped!" << std::endl;

	return ;
}

void		ClapTrap::meleeAttack(std::string const & target) const
{
	std::cout << "Ready for the PUNCHline? " << this->_name << " attacks " << target << " at melee, causing " 
			  << this->_meleeAtkDmg << " points of damage." << std::endl;	
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	int realAmount = amount == 0 ? 0 : amount - this->_armorDmgReduction;
	int hpLeft = this->_hitPoints - realAmount;

	this->_hitPoints = hpLeft < 0 ? 0 : hpLeft;

	std::cout << this->_name << " suffered " << realAmount << " points of damage. He has been left with " 
			  << this->_hitPoints << " HP" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << "YES !! YOU KILLED HIM !! Congrats, you made the world a better place." << std::endl;
	else
		std::cout << "Please kill him quick..." << std::endl;

	return ;
}


void		ClapTrap::beRepaired(unsigned int amount)
{
	int newHp = this->_hitPoints + amount;
	this->_hitPoints = newHp > this->_maxHitPoints ? this->_maxHitPoints : newHp;

	std::cout << this->_name << " was... repaired...? Why would anyone even do that ?!! Whatever, he recovered " 
			  << amount << " HP, bringing him to " << this->_hitPoints << " HP..." << std::endl;

	return ;
}