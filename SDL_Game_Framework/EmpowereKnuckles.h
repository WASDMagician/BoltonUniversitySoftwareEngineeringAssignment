#ifndef _EMPOWERREDKNUCKLES_H_
#define _EMPOWERREDKNUCKLES_H_

#include "Weapon.h"

class EmpowerredKnuckles :
	public Weapon
{
public:
	EmpowerredKnuckles();
	EmpowerredKnuckles(char* img, int x, int y);
	~EmpowerredKnuckles();

	void set_empowerredknuckles_damage(const double damage);
	const double get_empowerredknuckles_damage() const;

	void set_empowerredknuckles_range(const unsigned int range);
	const unsigned int get_empowerredknuckles_range() const;

	void set_empowerredknuckles_attackspeed(const double atkspd);
	const double get_empowerredknuckles_attackspeed() const;

private:
	double m_empowerredknuckles_damage_modifier; // damage modifier for empowerredknuckles = 0.75
	unsigned int m_empowerredknuckles_range; // empowerredknuckles == melee, range = 1
	double m_empowerredknuckles_attackspeed; // fastest, maybe 2
};
#endif