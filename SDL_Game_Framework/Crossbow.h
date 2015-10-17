#ifndef _CROSSBOW_H_
#define _CROSSBOW_H_

#include "Weapon.h"

class CrossBow :
	public Weapon
{
public:
	CrossBow();
	CrossBow(char* img, int x, int y);
	~CrossBow();

	void set_crossbow_damage(const double damage);
	const double get_crossbow_damage() const;

	void set_crossbow_range(const unsigned int range);
	const unsigned int get_crossbow_range() const;

	void set_crossbow_attackspeed(const double atkspd);
	const double get_crossbow_attackspeed() const;

private:
	double m_crossbow_damage_modifier; // damage modifier for crossbow = 0.5
	// feel like we need to add a range modifier for these weapons
	//i.e base 1 for melee 3 for ranged etc maybe , lets discuss in scrum
	unsigned int m_crossbow_range; // crossbow == ranged, range = 3
	double m_crossbow_attackspeed; // medium speed = 1
};
#endif