#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{

public:

	FragTrap(void);
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &inst);
	~FragTrap(void);

	FragTrap &			operator=(FragTrap const & rightOp);

	void				rangedAttack(std::string const & target) const;
	void				vaulthunter_dot_exe(std::string const & target);

private:

	void				_initClap(void);

};

#endif