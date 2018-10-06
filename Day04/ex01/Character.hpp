#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{

private:
	std::string 	_name;
	int 			_ap;
	AWeapon *		_curWeapon;
	Character();

public:
	Character(std::string const &name);
	Character(Character const &inst);
	~Character();

	Character &			operator=(Character const &rightOp);

	void				recoverAP();
	void				equip(AWeapon *weapon);
	void				attack(Enemy *enemy);

	std::string	const &	getName() const;
	int 				getAP() const;
	std::string			getWeapon() const;

};

std::ostream &			operator<<(std::ostream &o, Character const &rightOp);

#endif