#include "Shots.hpp"
#include "Enemy.hpp"

/*
	Constructors and destructors
*/

Shots::Shots() : AGameObject(0, 0, '-', 0, false, "Shots")
{

}

Shots::Shots(Shots const &inst)
{
	*this = inst;
}

Shots::~Shots()
{

}


/*
	Operator overloads
*/

Shots &			Shots::operator=(Shots const &rhs)
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

void                Shots::appearOnScreen(Context *context)
{
    (void)context;
}

void				Shots::appearInFront(Context *context, Coordinates pos)
{
    pos.x += 1;

    bool shotInFront = false;
    for (int i = 0 ; i < (int)Shots::shotsArr.size() ; i++)
    {
        Coordinates coord = Shots::shotsArr[i]->getCoordinates();
        if (coord == pos)
            shotInFront = true;
    }
    if (shotInFront == false)
    {
        _onScreen = true;
        _position = pos;
        mvwprintw(context->win, _position.y, _position.x, "%c", _display);
    }
}

void 				Shots::disappearFromScreen()
{
	_onScreen = false;
	_position.x = COLS + 1;
}

void 				Shots::move(Context *context, int x, int y)
{
	(void)y;
	if (_onScreen == false)
		return ;

	if (_scrollDelay == 0)
	{
		_scrollDelay = Shots::speed;	
		_position.x += x;

        for (int i = 0 ; i < MAX_ENEMY ; i++)
        {
            if (Enemy::enemyArr[i]->isOnScreen() == false)
                continue;
            Coordinates coord = Enemy::enemyArr[i]->getCoordinates();
            if (_position == coord)
            {
                Enemy::enemyArr[i]->disappearFromScreen();
                _onScreen = false;
                _position.x = COLS + 1;
            }
        }

		if (_position.x > COLS)
			_onScreen = false;
	}
	else
		_scrollDelay--;
	mvwprintw(context->win, _position.y, _position.x, "%c", _display);
}

/*
	Static array of Shots instances
*/

std::vector<Shots *>	    	Shots::shotsArr;
int 							Shots::speed = 1;
