#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int 	main(void)
{
	FragTrap clap1("Fraggy");
	ScavTrap clap2("Scavvy");

	std::cout << std::endl;

	clap1.takeDamage(10);
	clap2.takeDamage(10);

	std::cout << std::endl;

	clap1.beRepaired(5);
	clap2.beRepaired(5);

	std::cout << std::endl;

	clap1.rangedAttack("a cat");
	clap2.rangedAttack("a dog");

	std::cout << std::endl;

	clap1.meleeAttack("another cat");
	clap2.meleeAttack("another dog");

	std::cout << std::endl;

	clap1.vaulthunter_dot_exe("The King of Dogs");
	clap2.challengeNewcomer();

	std::cout << std::endl;

	return 0;
}