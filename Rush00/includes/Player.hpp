#ifndef PLAYER_HPP
# define PLAYER_HPP

/*
	The Player is a derived class of AGameObject.
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
	void			disappearFromScreen();						// Allows the object to disappear from the screen
	void			handleCollision(AGameObject *other);		// Allows to detect and handle the collision with another object
	void			move(Context *context, int n);				// Allows the object to implement its own moveset
};

#endif