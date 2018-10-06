#include "Player.hpp"

/*
	Constructors and destructors
*/

Player::Player() : AGameObject(0, 0, 'P', 0, false, "Player")
{

}

Player::Player(Player const &inst)
{
	*this = inst;
}

Player::~Player()
{

}


/*
	Operator overloads
*/

Player &			Player::operator=(Player const &rhs)
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

void				Player::appearOnScreen(Context *context)
{
	_onScreen = true;
	mvwprintw(context->win, _position.y, _position.x, "%c", _display);
}

void				Player::disappearFromScreen()
{
	_onScreen = false;
}

void				Player::handleCollision(AGameObject *other)
{

}

void 				Player::move(Context *context, int n)
{
	_position.y += n;
	mvwprintw(context->win, _position.y, _position.x, "%c", _display);
}