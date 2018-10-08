#include "Player.hpp"
#include "Enemy.hpp"

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
	_scrollDelay = rhs._scrollDelay;
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

void 				Player::move(Context *context, int x, int y)
{
	if (_onScreen == false)
		return ;

	if (_position.y > LINES)
		_position.y = LINES;
	if (_position.y + y >= 0 && _position.y + y < LINES)
		_position.y += y;
	if (_position.x + y >= 0 && _position.x + x < COLS)
		_position.x += x;

	for (int i = 0 ; i < (int)Enemy::enemyArr.size() ; i++)
	{
		Coordinates coord = Enemy::enemyArr[i]->getCoordinates();
		if (_position == coord)
		{
			_onScreen = false;
		}	
	}

	mvwprintw(context->win, _position.y, _position.x, "%c", _display);
}