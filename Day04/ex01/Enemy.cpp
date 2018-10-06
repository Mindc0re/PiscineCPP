#include "Enemy.hpp"

/*
	Constructors and destructors
*/

Enemy::Enemy()
{

}

Enemy::Enemy(int hp, std::string const &type) :
_hp(hp), _type(type)
{

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

Enemy &				Enemy::operator=(Enemy const &rightOp)
{
	this->_hp = rightOp._hp;
	this->_type = rightOp._type;

	return *this;
}


/*
	Member functions
*/

int 				Enemy::getHP() const
{
	return this->_hp;
}

std::string const &	Enemy::getType() const
{
	return this->_type;
}

void				Enemy::takeDamage(int dmg)
{
	if (dmg < 0)
		return ;

	this->_hp -= dmg;
}