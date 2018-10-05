#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:

	FragTrap(void);
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &inst);
	~FragTrap(void);

	FragTrap &			operator=(FragTrap const & rightOp);

	void				vaulthunter_dot_exe(std::string const & target);

private:

	void				_initFrag(void);

};

#endif