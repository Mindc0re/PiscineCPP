#include "Squad.hpp"

/*
	Constructors and destructors
*/

Squad::Squad()
{
	this->_list = NULL;
	this->_numberOfMarines = 0;
}

Squad::Squad(Squad const &inst)
{
	int 			unitCount = 0;
	t_marines *		tmp = inst._list;

	while (tmp)
	{
		push(tmp->unit);
		unitCount++;
	}
	this->_numberOfMarines = unitCount;
}

Squad::~Squad()
{
	this->_clearSquad();
}


/*
	Operator overloads
*/

Squad &				Squad::operator=(Squad const &rightOp)
{
	this->_clearSquad();

	t_marines *		tmp = rightOp._list;

	while (tmp)
		push(tmp->unit);

	this->_numberOfMarines = rightOp._numberOfMarines;

	return *this;
}


/*
	Member functions
*/

int 				Squad::getCount()  const
{
	return this->_numberOfMarines;
}

ISpaceMarine *		Squad::getUnit(int n) const
{
	if (this->_list == NULL || n >= this->_numberOfMarines || n < 0)
		return NULL;

	int 			i = 0;
	t_marines *		tmp = this->_list;

	while (i != n)
	{
		tmp = tmp->next;
		i++;
	}

	return tmp->unit;
}

int 				Squad::push(ISpaceMarine *unit)
{
	if (unit == NULL || _isAlreadyInSquad(unit))
		return this->_numberOfMarines;

	t_marines *		tmp = this->_list;
	t_marines *		newUnit = new t_marines();

	newUnit->unit = unit;
	newUnit->next = NULL;

	if (this->_numberOfMarines == 0)
		this->_list = newUnit;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newUnit;
	}

	this->_numberOfMarines += 1;

	return this->_numberOfMarines;
}

bool				Squad::_isAlreadyInSquad(ISpaceMarine *unit) const
{
	if (this->_list == NULL)
		return false;

	t_marines *		tmp = this->_list;

	while (tmp)
	{
		if (tmp->unit == unit)
			return true;
		tmp = tmp->next;
	}

	return false;

}

void				Squad::_clearSquad()
{
	t_marines *		tmp = this->_list;
	t_marines *		tmp2 = this->_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		delete(tmp->unit);
		tmp->unit = NULL;
		delete(tmp);
		tmp = NULL;
		tmp = tmp2;
	}
}
