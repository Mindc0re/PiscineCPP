#include "Sorcerer.hpp"

/*
	Constructors and destructors
*/

Sorcerer::Sorcerer(std::string const &name, std::string const &title) :
_name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const &inst)
{
	*this = inst;

	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;

	return ;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;

	return ;
}


/*
	Operator overloads
*/

Sorcerer &		Sorcerer::operator=(Sorcerer const &rightOp)
{
	this->_name = rightOp._name;
	this->_title = rightOp._title;

	return *this;
}

std::ostream &	operator<<(std::ostream &o, Sorcerer const &rightOp)
{
	o << "I am " << rightOp.getName() << ", " << rightOp.getTitle() << ", and I like ponies !" << std::endl;

	return o;
}


/*
	Member functions
*/

std::string		Sorcerer::getName() const
{
	return this->_name;
}

std::string		Sorcerer::getTitle() const
{
	return this->_title;
}

void			Sorcerer::polymorph(Victim const &v) const
{
	v.getPolymorphed();

	return ;
}