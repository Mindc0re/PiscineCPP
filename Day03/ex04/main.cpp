#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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

	SuperTrap clap5("Clark Kent Trap");
	std::cout << std::endl;

	clap5.takeDamage(10);
	std::cout << std::endl;

	clap5.beRepaired(10);
	std::cout << std::endl;

	clap5.rangedAttack("Sauron");
	std::cout << std::endl;

	clap5.meleeAttack("Voldemort");
	std::cout << std::endl;

	clap5.vaulthunter_dot_exe("Darth Vader");
	std::cout << std::endl;

	clap5.ninjaShoebox(clap4);

	std::cout << std::endl;

	return 0;
}