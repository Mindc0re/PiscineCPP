#include "Victim.hpp"

/*
	Constructors and destructors
*/

Victim::Victim()
{
	
}

Victim::Victim(std::string const &name) :
_name(name)
{
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
	return ;
}

Victim::Victim(Victim const &inst)
{
	*this = inst;

	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;

	return ;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;

	return ;
}


/*
	Operator overloads
*/

Victim &		Victim::operator=(Victim const &rightOp)
{
	this->_name = rightOp._name;

	return *this;
}

std::ostream &	operator<<(std::ostream &o, Victim const &rightOp)
{
	o << "I'm " << rightOp.getName() << " and I like otters !" << std::endl;

	return o;
}


/*
	Member functions
*/

std::string		Victim::getName() const
{
	return this->_name;
}

void			Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;

	return ;
}