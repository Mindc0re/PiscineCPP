#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{

public:

	SuperTrap(void);
	SuperTrap(std::string const &name);
	SuperTrap(SuperTrap const &inst);
	~SuperTrap(void);

	SuperTrap &			operator=(SuperTrap const & rightOp);

	void				rangedAttack(std::string const & target) const;
	void				meleeAttack(std::string const & target) const;

private:

	void				_initClap(void);

};

#endif