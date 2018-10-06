#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{

protected:
	std::string		_name;
	int 			_apCost;
	int 			_damage;

	AWeapon();

public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &inst);
	virtual ~AWeapon();

	std::string		getName() const;
	int 			getAPCost() const;
	int 			getDamage() const;

	virtual void 	attack() const = 0;

	AWeapon &		operator=(AWeapon const &rightOp);

};

#endif
