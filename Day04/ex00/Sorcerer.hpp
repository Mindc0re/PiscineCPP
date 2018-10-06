#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{

public:
	Sorcerer(std::string const &name, std::string const &title);
	Sorcerer(Sorcerer const &inst);
	~Sorcerer();

	Sorcerer &		operator=(Sorcerer const & rightOp);
	
	std::string		getName() const;
	std::string		getTitle() const;

	void			polymorph(Victim const &v) const;

private:
	Sorcerer();

	std::string		_name;
	std::string		_title;
	
};

std::ostream &		operator<<(std::ostream &o, Sorcerer const &rightOp);

#endif