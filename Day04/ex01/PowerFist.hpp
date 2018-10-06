#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{

public:
	PowerFist();
	PowerFist(PowerFist const &inst);
	~PowerFist();

	PowerFist &		operator=(PowerFist const &rightOp);

	void 			attack() const;

};

#endif
