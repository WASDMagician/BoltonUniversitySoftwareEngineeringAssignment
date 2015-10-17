#ifndef _EMPOWERED_KNUCKLES_H_
#define _EMPOWERED_KNUCKLES_H_

#include "Weapon.h"

class Empowered_Knuckles :
	public Weapon
{
public:
	Empowered_Knuckles();
	Empowered_Knuckles(char* img, int x, int y);
	~Empowered_Knuckles();

	void set_empowered_knuckles_damage(const double damage);
	const double get_empowered_knuckles_damage() const;

	void set_empowered_knuckles_range(const unsigned int range);
	const unsigned int get_empowered_knuckles_range() const;

	void set_empowered_knuckles_attackspeed(const double atkspd);
	const double get_empowered_knuckles_attackspeed() const;

private:
	double m_empowered_knuckles_damage_modifier; // damage modifier for empowered_knuckles = 0.75
	unsigned int m_empowered_knuckles_range; // empowered_knuckles == melee, range = 1
	double m_empowered_knuckles_attackspeed; // fastest, maybe 2
};
#endif