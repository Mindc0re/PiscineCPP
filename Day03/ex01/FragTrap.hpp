#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap
{

public:

	FragTrap(void);
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &inst);
	~FragTrap(void);

	FragTrap &			operator=(FragTrap const & rightOp);

	void				rangedAttack(std::string const & target) const;
	void				meleeAttack(std::string const & target) const;
	void				takeDamage(unsigned int amount);
	void 				beRepaired(unsigned int amount);

	void				vaulthunter_dot_exe(std::string const & target);

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