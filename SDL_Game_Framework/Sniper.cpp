#include "Sniper.h"
// Niall -> Sniper Strongest but Slowest, Longest range (range)

Sniper::Sniper()
{
	//default metrics for sniper
	//make this rarer than crossbow as it is super op
	m_sniper_damage_modifier = 3;
	m_sniper_range = 5;
	m_sniper_attackspeed = 0.25;
}

Sniper::Sniper(char*img, int rows, int cols)
:Weapon(img, rows, cols)
{
}

Sniper::~Sniper()
{

}

void Sniper::set_sniper_damage(const double damage)
{
	m_sniper_damage_modifier = damage;
}
const double Sniper::get_sniper_damage() const
{
	return m_sniper_damage_modifier;
}

void Sniper::set_sniper_range(const unsigned int range)
{
	m_sniper_range = range;
}

const unsigned int Sniper::get_sniper_range() const
{
	return m_sniper_range;
}

void Sniper::set_sniper_attackspeed(const double atkspd)
{
	m_sniper_attackspeed = atkspd;
}

const double Sniper::get_sniper_attackspeed() const
{
	return m_sniper_attackspeed;
}
