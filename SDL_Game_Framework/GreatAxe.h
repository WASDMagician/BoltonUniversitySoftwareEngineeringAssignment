#ifndef _GREATAXE_H_
#define _GREATAXE_H_

#include "Weapon.h"

class GreatAxe :
	public Weapon
{
public:
	GreatAxe();
	GreatAxe(char* img, int x, int y);
	~GreatAxe();

	void set_greataxe_damage(const double damage);
	const double get_greataxe_damage() const;

	void set_greataxe_range(const unsigned int range);
	const unsigned int get_greataxe_range() const;

	void set_greataxe_attackspeed(const double atkspd);
	const double get_greataxe_attackspeed() const;

private:
	double m_greataxe_damage_modifier; // damage modifier for greataxe = 1.5
	unsigned int m_greataxe_range; // greataxe == melee, range = 1
	double m_greataxe_attackspeed; // slowest, maybe 0.5
};
#endif