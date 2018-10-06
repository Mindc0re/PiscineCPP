#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy
{

public:
	RadScorpion();
	RadScorpion(RadScorpion const &inst);
	~RadScorpion();

	RadScorpion &	operator=(RadScorpion const &rightOp);

};

#endif