#ifndef _SWORD_H_
#define _SWORD_H_

#include "Weapon.h"

class Sword :
	public Weapon
{
public:
	Sword();
	Sword(weapon_constructor_variables *initialiser);
	~Sword();

	void set_sword_damage(const double damage);
	const double get_sword_damage() const;

	void set_sword_range(const unsigned int range);
	const unsigned int get_sword_range() const;

	void set_sword_attackspeed(const double atkspd);
	const double get_sword_attackspeed() const;

private:
	double m_sword_damage_modifier; // damage modifier for sword = 1
	unsigned int m_sword_range; // sword == melee, range = 1
	double m_sword_attackspeed; // fastest = 1.5
};
#endif