#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include <iostream>

class Squad : public ISquad
{

public:

	typedef struct 		s_marines
	{
		ISpaceMarine *	unit;
		s_marines *		next;
	}					t_marines;

	Squad();
	Squad(Squad const &inst);
	~Squad();

	int 				getCount() const;
	ISpaceMarine *		getUnit(int n) const;
	int 				push(ISpaceMarine *unit);

	Squad &				operator=(Squad const &rightOp);

private:

	t_marines *			_list;
	int 				_numberOfMarines;
	bool				_isAlreadyInSquad(ISpaceMarine *unit) const;
	void				_clearSquad();

};

#endif