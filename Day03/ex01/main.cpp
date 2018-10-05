#include "FragTrap.hpp"

int 	main(void)
{
	FragTrap clap1;
	FragTrap clap2("Clappy");

	std::cout << std::endl;

	clap1.rangedAttack("Handsome Jack");
	clap1.rangedAttack("");
	clap2.meleeAttack("T.K. Baha");

	std::cout << std::endl;

	clap1.takeDamage(10);
	clap1.takeDamage(0);
	clap1.takeDamage(1000);

	std::cout << std::endl;

	clap1.beRepaired(0);
	clap1.beRepaired(10);
	clap1.beRepaired(1000);

	std::cout << std::endl;

	clap1.takeDamage(20);

	clap2 = clap1;

	std::cout << std::endl;

	clap2.beRepaired(5);

	FragTrap clap3(clap1);
	clap3.takeDamage(10);

	std::cout << std::endl;

	clap1.vaulthunter_dot_exe("Moxxi");
	std::cout << std::endl;
	clap1.vaulthunter_dot_exe("Marcus Kincaid");
	std::cout << std::endl;
	clap1.vaulthunter_dot_exe("Patricia Tannis");
	std::cout << std::endl;
	clap1.vaulthunter_dot_exe("General Knoxx");
	std::cout << std::endl;
	clap1.vaulthunter_dot_exe("Dr. Ned");

	std::cout << std::endl;	
}