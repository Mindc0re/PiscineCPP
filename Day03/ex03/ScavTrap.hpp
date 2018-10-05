#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:

	ScavTrap(void);
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &inst);
	~ScavTrap(void);

	ScavTrap &			operator=(ScavTrap const & rightOp);

	void				challengeNewcomer(void);

private:

	void				_initScav(void);

};

#endif