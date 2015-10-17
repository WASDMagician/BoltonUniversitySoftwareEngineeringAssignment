#include "GreatAxe.h"
// Niall -> Greataxe Strongest but Slowest, Normal range (melee)
GreatAxe::GreatAxe()
{
	//default metrics for greataxe
	m_greataxe_damage_modifier = 1.5;
	m_greataxe_range = 1;
	m_greataxe_attackspeed = 0.5;
}

GreatAxe::GreatAxe(char*img, int x, int y)
:Weapon(img, 0, 0)
{
	set_world_position((float)x, (float)y);
}

GreatAxe::~GreatAxe()
{

}

void GreatAxe::set_greataxe_damage(const double damage)
{
	m_greataxe_damage_modifier = damage;
}
const double GreatAxe::get_greataxe_damage() const
{
	return m_greataxe_damage_modifier;
}

void GreatAxe::set_greataxe_range(const unsigned int range)
{
	m_greataxe_range = range;
}

const unsigned int GreatAxe::get_greataxe_range() const
{
	return m_greataxe_range;
}

void GreatAxe::set_greataxe_attackspeed(const double atkspd)
{
	m_greataxe_attackspeed = atkspd;
}

const double GreatAxe::get_greataxe_attackspeed() const
{
	return m_greataxe_attackspeed;
}