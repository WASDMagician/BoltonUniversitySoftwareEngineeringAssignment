#ifndef _GREATAXE_H_
#define _GREATAXE_H_

#include "Weapon.h"

class Great_Axe :
	public Weapon
{
public:
	Great_Axe();
	Great_Axe(char* img, int x, int y);
	~Great_Axe();

	void set_great_axe_damage(const double damage);
	const double get_great_axe_damage() const;

	void set_great_axe_range(const unsigned int range);
	const unsigned int get_great_axe_range() const;

	void set_great_axe_attackspeed(const double atkspd);
	const double get_great_axe_attackspeed() const;

private:
	double m_great_axe_damage_modifier; // damage modifier for great_axe = 1.5
	unsigned int m_great_axe_range; // great_axe == melee, range = 1
	double m_great_axe_attackspeed; // slowest, maybe 0.5
};
#endif