#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int 	main(void)
{
	FragTrap clap1("Clappy");
	ScavTrap clap2("King ScavTrap");
	ScavTrap clap3;

	std::cout << std::endl;

	clap2.rangedAttack("Handsome Jack");
	clap2.meleeAttack("T.K. Baha");

	std::cout << std::endl;

	clap2.takeDamage(10);
	clap3.takeDamage(10);
	clap1.takeDamage(0);
	clap1.takeDamage(1000);
	clap2.takeDamage(1000);

	std::cout << std::endl;

	clap1.beRepaired(0);
	clap1.beRepaired(10);
	clap2.beRepaired(1000);
	clap3.beRepaired(1);

	std::cout << std::endl;

	clap1.takeDamage(20);

	clap3 = clap2;

	std::cout << std::endl;

	clap3.beRepaired(5);

	ScavTrap clap4(clap3);
	clap4.takeDamage(10);

	std::cout << std::endl;

	clap4.challengeNewcomer();
	std::cout << std::endl;
	clap4.challengeNewcomer();
	std::cout << std::endl;
	clap4.challengeNewcomer();
	std::cout << std::endl;
	clap4.challengeNewcomer();
	std::cout << std::endl;
	clap4.challengeNewcomer();

	std::cout << std::endl;	
}