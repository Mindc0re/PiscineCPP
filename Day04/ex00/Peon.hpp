#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim
{

public:

	Peon(std::string const &name);
	Peon(Peon const &inst);
	~Peon();

	Peon &		operator=(Peon const & rightOp);

	std::string		getName() const;

	virtual void	getPolymorphed() const;

private:

	Peon();

};

std::ostream &		operator<<(std::ostream &o, Peon const &rightOp);

#endif