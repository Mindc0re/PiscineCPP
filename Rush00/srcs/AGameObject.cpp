#include "AGameObject.hpp"

/*
	Constructors and destructors
*/

AGameObject::AGameObject()
{

}

AGameObject::AGameObject(int x, int y, char display, int scrollSpeed, bool onScreen, std::string type) :
_position(Coordinates(x, y)), _display(display), _scrollSpeed(scrollSpeed), _onScreen(onScreen), _type(type)
{

}

AGameObject::AGameObject(AGameObject const &inst)
{
	*this = inst;
}

AGameObject::~AGameObject()
{

}


/*
	Operator overloads
*/

AGameObject &			AGameObject::operator=(AGameObject const &rhs)
{
	_position = rhs._position;
	_display = rhs._display;
	_scrollSpeed = rhs._scrollSpeed;
	_onScreen = rhs._onScreen;

	return *this;
}


/*
	Member functions
*/

Coordinates				AGameObject::getCoordinates() const
{
	return _position;
}

int 					AGameObject::getScrollSpeed() const
{
	return _scrollSpeed;
}

bool 					AGameObject::isOnScreen() const
{
	return _onScreen;
}

void					AGameObject::setDisplay(char c)
{
	_display = c;
}