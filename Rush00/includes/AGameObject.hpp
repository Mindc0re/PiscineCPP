#ifndef AGAMEOBJECT_HPP
# define AGAMEOBJECT_HPP

/*
	The AGameObject class will define all objects that will be displayed on the game screen.
	It is an abstract clas, and thus cannot be instanciated.
*/

# include "Context.hpp"
# include "Coordinates.hpp"

class AGameObject
{

protected:
	Coordinates		_position;				// An instance of the Coordinates class, which contains the X and Y coordinates of the object
	char			_display;				// The character used for the display on the screen
	int				_scrollSpeed;			// The speed at which the game object scrolls in the screen
	bool			_onScreen;				// isOnScreen indicates whether or not the GameObject is displayed on the screen
	std::string		_type;					// The type of the GameObject : Player, Missile or Enemy

	AGameObject();												// Default constructor

public:
	AGameObject(int, int, char, int, bool, std::string);		// Constructor that takes parameters
	AGameObject(AGameObject const &inst);						// Copy constructor
	virtual ~AGameObject();										// Destructor

	AGameObject &	operator=(AGameObject const &rhs);			// Assignation overload

	virtual void	appearOnScreen(Context *context) = 0;		// Allows to make the object appear on the screen
	virtual void	disappearFromScreen() = 0;					// Allows the object to disappear from the screen
	virtual void	handleCollision(AGameObject *other) = 0;	// Allows to handle the collision with another object
	virtual void	move(Context *context, int n) = 0;			// Allows the object to implement its own moveset and detect collisions

	Coordinates		getCoordinates() const;						// Allows to get the X and Y coordinates of the object
	int 			getScrollSpeed() const;						// Allows to get the scroll speed of the object
	bool 			isOnScreen() const;							// Allows to know if the object is on the screen

	void 			setDisplay(char c);							// This setter allows to change the display character of the object
};

#endif