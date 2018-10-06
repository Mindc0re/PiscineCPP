#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{

	Character* zaz = new Character("zaz");

	std::cout << *zaz;

	Enemy* scorp = new RadScorpion();
	Enemy* mutant = new SuperMutant();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	
	zaz->equip(pf);

	zaz->attack(scorp);
	std::cout << *zaz;
	
	zaz->equip(pr);
	std::cout << *zaz;
	
	zaz->attack(scorp);
	std::cout << *zaz;
	
	zaz->attack(scorp);
	std::cout << *zaz;

	zaz->equip(pf);
	zaz->attack(mutant);
	zaz->attack(mutant);
	std::cout << *zaz;
	zaz->attack(mutant);

	std::cout << "Mutant has " << mutant->getHP() << " HP left" << std::endl;
	mutant->takeDamage(2);
	std::cout << "Mutant has " << mutant->getHP() << " HP left" << std::endl;

	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;

	zaz->equip(NULL);
	std::cout << *zaz;

	zaz->attack(mutant);
	std::cout << "Mutant has " << mutant->getHP() << " HP left" << std::endl;

	zaz->equip(pf);

	zaz->attack(mutant);
	zaz->attack(mutant);
	
	std::cout << *zaz;

	return 0;

}
