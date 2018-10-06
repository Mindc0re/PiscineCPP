#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{

public:
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &inst);
	~PlasmaRifle();

	PlasmaRifle &		operator=(PlasmaRifle const &rightOp);

	void 				attack() const;

};

#endif
