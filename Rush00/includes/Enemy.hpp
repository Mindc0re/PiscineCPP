#ifndef ENEMY_HPP
# define ENEMY_HPP

/*
	The Enemy class is a derived class of AGameObject.
	This class can represent an enemy.
*/

# include "AGameObject.hpp"

class Enemy : public AGameObject
{

public:
	Enemy();													// Default constructor
	Enemy(Enemy const &inst);									// Copy constructor
	~Enemy();													// Destructor

	Enemy &			operator=(Enemy const &rhs);				// Assignation overload

	void			appearOnScreen(Context *context);			// Allows to make the object appear on the screen
	void 			disappearFromScreen();
	void			move(Context *context, int x, int y);				// Allows the object to implement its own moveset

	int 			spawnDelay;

	static std::vector<Enemy *>				enemyArr;
	static int 								speed;

private:
	void 			_spawn();
	void			_respawn();

	static std::string						_charset;
};

#endif