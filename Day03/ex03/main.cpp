#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int 	main(void)
{
	ClapTrap clap0("El Claptrapo");
	std::cout << std::endl;

	FragTrap clap1("Fraggy");
	std::cout << std::endl;

	ScavTrap clap2("Scavvy");
	std::cout << std::endl;

	NinjaTrap clap3("NarutoTrap");
	std::cout << std::endl;

	NinjaTrap clap4("SasukeTrap");
	std::cout << std::endl;

	clap0.takeDamage(10);
	clap1.takeDamage(10);
	clap2.takeDamage(10);
	clap3.takeDamage(10);

	std::cout << std::endl;

	clap0.beRepaired(5);
	clap1.beRepaired(5);
	clap2.beRepaired(5);
	clap3.beRepaired(5);

	std::cout << std::endl;

	clap0.rangedAttack("himself");
	clap1.rangedAttack("a cat");
	clap2.rangedAttack("a dog");
	clap4.rangedAttack("a tree");

	std::cout << std::endl;

	clap0.meleeAttack("himself, again,");
	clap1.meleeAttack("another cat");
	clap2.meleeAttack("another dog");
	clap4.meleeAttack("a tree");

	std::cout << std::endl;

	clap1.vaulthunter_dot_exe("The King of Dogs");
	std::cout << std::endl;

	clap2.challengeNewcomer();
	std::cout << std::endl;

	clap3.ninjaShoebox(clap0);
	std::cout << std::endl;

	clap3.ninjaShoebox(clap1);
	std::cout << std::endl;

	clap3.ninjaShoebox(clap2);
	std::cout << std::endl;

	clap3.ninjaShoebox(clap4);

	std::cout << std::endl;

	return 0;
}