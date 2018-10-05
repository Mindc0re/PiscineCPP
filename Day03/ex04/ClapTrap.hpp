#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{

public:

	ClapTrap(void);
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &inst);
	~ClapTrap(void);

	ClapTrap &			operator=(ClapTrap const & rightOp);

	void				rangedAttack(std::string const & target) const;
	void				meleeAttack(std::string const & target) const;
	void				takeDamage(unsigned int amount);
	void 				beRepaired(unsigned int amount);

protected:

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