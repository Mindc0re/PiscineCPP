#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{

protected:
	int 				_hp;
	std::string			_type;

	Enemy();

public:
	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &inst);
	virtual ~Enemy();

	Enemy &				operator=(Enemy const &rightOp);

	int 				getHP() const;
	std::string	const &	getType() const;

	virtual void		takeDamage(int dmg);

};

#endif