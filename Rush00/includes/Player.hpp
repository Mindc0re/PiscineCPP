#ifndef PLAYER_HPP
# define PLAYER_HPP

/*
	The Player class is a derived class of AGameObject.
	This class represents the playable character on the screen.
*/

# include "AGameObject.hpp"

class Player : public AGameObject
{

public:
	Player();													// Default constructor
	Player(Player const &inst);									// Copy constructor
	~Player();													// Destructor

	Player &		operator=(Player const &rhs);				// Assignation overload

	void			appearOnScreen(Context *context);			// Allows to make the object appear on the screen
	void			move(Context *context, int x, int y);				// Allows the object to implement its own moveset
};

#endif