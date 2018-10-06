#include "TacticalMarine.hpp"

/*
	Constructors and destructors
*/

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &inst)
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
	*this = inst;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh ..." << std::endl;
}


/*
	Operator overloads
*/

TacticalMarine &	TacticalMarine::operator=(TacticalMarine const &rightOp)
{
	(void)rightOp;
	return *this;
}

/*
	Member functions
*/

ISpaceMarine *		TacticalMarine::clone() const
{
	ISpaceMarine *newUnit = new TacticalMarine(*this);
	return newUnit;
}

void				TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT !" << std::endl;	
}

void				TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *" << std::endl;	
}

void				TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}