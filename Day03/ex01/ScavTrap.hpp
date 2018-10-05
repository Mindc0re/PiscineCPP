#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap
{

public:

	ScavTrap(void);
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &inst);
	~ScavTrap(void);

	ScavTrap &			operator=(ScavTrap const & rightOp);

	void				rangedAttack(std::string const & target) const;
	void				meleeAttack(std::string const & target) const;
	void				takeDamage(unsigned int amount);
	void 				beRepaired(unsigned int amount);

	void				challengeNewcomer(void);

private:

	int 				_hitPoints;
	int 				_maxHitPoints;
	int 				_energyPoints;
	int 				_maxEnergyPoints;
	int 				_level;
	std::string			_name;
	int 				_meleeAtkDmg;
	int 				_rangedAtkDmg;
	int 				_armorDmgReduction;

};

#endif