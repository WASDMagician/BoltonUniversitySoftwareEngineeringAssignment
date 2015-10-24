#ifndef _SNIPER_H_
#define _SNIPER_H_

#include "Weapon.h"

class Sniper :
	public Weapon
{
public:
	Sniper();
	Sniper(weapon_constructor_variables *initialiser);
	~Sniper();

	void set_sniper_damage(const double damage);
	const double get_sniper_damage() const;

	void set_sniper_range(const unsigned int range);
	const unsigned int get_sniper_range() const;

	void set_sniper_attackspeed(const double atkspd);
	const double get_sniper_attackspeed() const;

private:
	double m_sniper_damage_modifier; // damage modifier for sniper = 3
	unsigned int m_sniper_range; // sniper == ranged, longest range = 5
	double m_sniper_attackspeed; // slowest ranged, maybe 0.25
};
#endif
