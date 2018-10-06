#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{

public:

	Victim(std::string const &name);
	Victim(Victim const &inst);
	~Victim();

	Victim &		operator=(Victim const & rightOp);

	std::string		getName() const;

	virtual void	getPolymorphed() const;

protected:

	Victim();

	std::string		_name;
	
};

std::ostream &		operator<<(std::ostream &o, Victim const &rightOp);

#endif