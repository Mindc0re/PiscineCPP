#include "Peon.hpp"

/*
	Constructors and destructors
*/

Peon::Peon() : Victim()
{
	
}

Peon::Peon(std::string const &name) : Victim(name)
{
	this->_name = name;
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::Peon(Peon const &inst)
{
	*this = inst;

	std::cout << "Zog zog." << std::endl;

	return ;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;

	return ;
}


/*
	Operator overloads
*/

Peon &		Peon::operator=(Peon const &rightOp)
{
	this->_name = rightOp._name;

	return *this;
}

std::ostream &	operator<<(std::ostream &o, Peon const &rightOp)
{
	o << "I'm " << rightOp.getName() << " and I like otters !" << std::endl;

	return o;
}


/*
	Member functions
*/

std::string		Peon::getName() const
{
	return this->_name;
}

void			Peon::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;

	return ;
}