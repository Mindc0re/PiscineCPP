#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{

public:

	NinjaTrap(void);
	NinjaTrap(std::string const &name);
	NinjaTrap(NinjaTrap const &inst);
	~NinjaTrap(void);

	NinjaTrap &			operator=(NinjaTrap const & rightOp);

	void				ninjaShoebox(ClapTrap &clap);
	void				ninjaShoebox(FragTrap &clap);
	void				ninjaShoebox(ScavTrap &clap);
	void				ninjaShoebox(NinjaTrap &clap);

private:

	void				_initNinja(void);

};

#endif