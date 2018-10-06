#include "AssaultTerminator.hpp"

/*
	Constructors and destructors
*/

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &inst)
{
	std::cout << "* teleports from space *" << std::endl;
	*this = inst;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back ..." << std::endl;
}


/*
	Operator overloads
*/

AssaultTerminator &	AssaultTerminator::operator=(AssaultTerminator const &rightOp)
{
	(void)rightOp;
	return *this;
}

/*
	Member functions
*/

ISpaceMarine *		AssaultTerminator::clone() const
{
	ISpaceMarine *newUnit = new AssaultTerminator(*this);
	return newUnit;
}

void				AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;	
}

void				AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;	
}

void				AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}