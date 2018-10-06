#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"
# include <iostream>

class AssaultTerminator : public ISpaceMarine
{

public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const &inst);
	~AssaultTerminator();
	
	AssaultTerminator &	operator=(AssaultTerminator const &rightOp);

	ISpaceMarine * 		clone() const;
	
	void 				battleCry() const;
	void 				rangedAttack() const;
	void 				meleeAttack() const;

};

#endif