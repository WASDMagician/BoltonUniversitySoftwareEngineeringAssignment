#include "EmpowereKnuckles.h"
// Niall -> EmpowerredKnuckles Weak but Fastest, Normal range (melee)

EmpowerredKnuckles::EmpowerredKnuckles()
{
	//default metrics for empowerredknuckles
	//make this rarer than sword, as it is overall more dps
	m_empowerredknuckles_damage_modifier = 0.75;
	m_empowerredknuckles_range = 1;
	m_empowerredknuckles_attackspeed = 2;
}

EmpowerredKnuckles::EmpowerredKnuckles(char*img, int x, int y)
:Weapon(img, 0, 0)
{
	set_world_position((float)x, (float)y);
}

EmpowerredKnuckles::~EmpowerredKnuckles()
{

}

void EmpowerredKnuckles::set_empowerredknuckles_damage(const double damage)
{
	m_empowerredknuckles_damage_modifier = damage;
}
const double EmpowerredKnuckles::get_empowerredknuckles_damage() const
{
	return m_empowerredknuckles_damage_modifier;
}

void EmpowerredKnuckles::set_empowerredknuckles_range(const unsigned int range)
{
	m_empowerredknuckles_range = range;
}

const unsigned int EmpowerredKnuckles::get_empowerredknuckles_range() const
{
	return m_empowerredknuckles_range;
}

void EmpowerredKnuckles::set_empowerredknuckles_attackspeed(const double atkspd)
{
	m_empowerredknuckles_attackspeed = atkspd;
}

const double EmpowerredKnuckles::get_empowerredknuckles_attackspeed() const
{
	return m_empowerredknuckles_attackspeed;
}
