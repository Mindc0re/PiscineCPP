#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy
{

public:
	SuperMutant();
	SuperMutant(SuperMutant const &inst);
	~SuperMutant();

	SuperMutant &	operator=(SuperMutant const &rightOp);

	void	takeDamage(int dmg);

};

#endif