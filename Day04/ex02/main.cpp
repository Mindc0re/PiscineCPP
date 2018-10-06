#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* squad = new Squad;

	std::cout << "\nSquad has " << squad->getCount() << " units." << std::endl;

	squad->push(bob);

	squad->push(jim);

	std::cout << "Squad has " << squad->getCount() << " units.\n" << std::endl;

	squad->push(NULL);
	squad->push(bob);
	squad->push(jim);

	std::cout << "Squad has " << squad->getCount() << " units.\n" << std::endl;

	ISpaceMarine *nullMarine = squad->getUnit(3);
	std::cout << "Wrong call to getUnit with out of bound index is " << nullMarine << std::endl;
	nullMarine = squad->getUnit(-1);
	std::cout << "Wrong call to getUnit with negative index is " << nullMarine << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < squad->getCount(); ++i)
	{
		ISpaceMarine* cur = squad->getUnit(i);

		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		
		std::cout << std::endl;
	}
	delete squad;

	return 0;
}