#include "Enemy.hpp"
#include "Shots.hpp"

/*
	Constructors and destructors
*/

Enemy::Enemy() : AGameObject(COLS - 5, 0, 'E', 0, false, "Enemy")
{
	_spawn();
	spawnDelay = 0;
}

Enemy::Enemy(Enemy const &inst)
{
	*this = inst;
}

Enemy::~Enemy()
{

}


/*
	Operator overloads
*/

Enemy &			Enemy::operator=(Enemy const &rhs)
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

void				Enemy::appearOnScreen(Context *context)
{
	_onScreen = true;
	mvwprintw(context->win, _position.y, _position.x, "%c", _display);
}

void 				Enemy::disappearFromScreen()
{
	_onScreen = false;
	_position.x = -1;
}

void 				Enemy::move(Context *context, int x, int y)
{
	(void)y;
	if (_onScreen == false)
	{
		_respawn();
		return ;
	}
	if (_scrollDelay == 0)
	{
		_scrollDelay = Enemy::speed;	
		_position.x += x;

		for (int i = 0 ; i < MAX_SHOTS ; i++)
        {
			if (Shots::shotsArr[i]->isOnScreen() == false)
                continue;
            Coordinates coord = Shots::shotsArr[i]->getCoordinates();
            if (_position == coord)
            {
                Shots::shotsArr[i]->disappearFromScreen();
                _onScreen = false;
            }
        }


		if (_position.x < 0)
		{
			_onScreen = false;
			spawnDelay = rand() % 1000 + 1000;
		}
	}
	else
		_scrollDelay--;
	mvwprintw(context->win, _position.y, _position.x, "%c", _display);
}

void				Enemy::_spawn()
{
	int randY = rand() % LINES;

	for (int i = 0 ; i < (int)Enemy::enemyArr.size() ; i++)
	{
		Coordinates coord = Enemy::enemyArr[i]->getCoordinates();
		while (randY == coord.y)
			randY = rand() % LINES;
	}
	_position.y = randY;

	_display = _charset[rand() % 24];
}

void				Enemy::_respawn()
{
	if (spawnDelay == 0)
	{
		_onScreen = true;
		_spawn();
		_position.x = COLS - 5;
	}
	else
		spawnDelay--;
}

/*
	Static array of Enemy instances
*/

std::vector<Enemy *>			Enemy::enemyArr;
int 							Enemy::speed = 3;
std::string						Enemy::_charset = "!#$%&()*+/:;<=>?@[\\]{|}";
