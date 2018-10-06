#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main(void)
{
	Sorcerer gandalf("Gandalf", "the Grey");
	Sorcerer gandalf2(gandalf);
	Sorcerer gandoulf("Gandoulf", "the Old");

	std::cout << gandalf << std::endl;
	gandalf = gandoulf;
	std::cout << gandalf << std::endl << std::endl;


	Victim krilin("Krilin");
	Victim krilin2(krilin);
	Victim foo("Foo");

	std::cout << foo << std::endl;
	foo = krilin;
	std::cout << foo << std::endl << std::endl;
	gandoulf.polymorph(krilin2);
	std::cout << std::endl;


	Peon *kenny = new Peon("Kenny");
	Victim *bar = new Peon("Bar");

	std::cout << *kenny << std::endl;
	std::cout << *bar << std::endl;
	gandoulf.polymorph(*kenny);
	gandoulf.polymorph(*bar);

	delete(kenny);
	delete(bar);

	return 0;
}