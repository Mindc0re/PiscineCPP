#ifndef SHOTS_HPP
# define SHOTS_HPP

/*
	The Shots class is a derived class of AGameObject.
	This class can represent a Shot shot by the player.
*/

# include "AGameObject.hpp"

class Shots : public AGameObject
{

public:
	Shots();													// Default constructor
	Shots(Shots const &inst);									// Copy constructor
	~Shots();													// Destructor

	Shots &			operator=(Shots const &rhs);				// Assignation overload

	void	        appearOnScreen(Context *context);			// Allows to make the object appear on the screen
    virtual void	appearInFront(Context *context, Coordinates pos);
    void 			disappearFromScreen();
	void			move(Context *context, int x, int y);				// Allows the object to implement its own moveset

	static std::vector<Shots *>     		shotsArr;
	static int 								speed;
};

#endif