#include "Empowere_Knuckles.h"
// Niall -> empowered_knuckles Weak but Fastest, Normal range (melee)

Empowered_Knuckles::Empowered_Knuckles()
{
	//default metrics for empowered_knuckles
	//make this rarer than sword, as it is overall more dps
	m_empowered_knuckles_damage_modifier = 0.75;
	m_empowered_knuckles_range = 1;
	m_empowered_knuckles_attackspeed = 2;
}

Empowered_Knuckles::Empowered_Knuckles(char*img, int rows, int cols)
:Weapon(img, rows, cols)
{
}

Empowered_Knuckles::~Empowered_Knuckles()
{

}

void Empowered_Knuckles::set_empowered_knuckles_damage(const double damage)
{
	m_empowered_knuckles_damage_modifier = damage;
}
const double Empowered_Knuckles::get_empowered_knuckles_damage() const
{
	return m_empowered_knuckles_damage_modifier;
}

void Empowered_Knuckles::set_empowered_knuckles_range(const unsigned int range)
{
	m_empowered_knuckles_range = range;
}

const unsigned int Empowered_Knuckles::get_empowered_knuckles_range() const
{
	return m_empowered_knuckles_range;
}

void Empowered_Knuckles::set_empowered_knuckles_attackspeed(const double atkspd)
{
	m_empowered_knuckles_attackspeed = atkspd;
}

const double Empowered_Knuckles::get_empowered_knuckles_attackspeed() const
{
	return m_empowered_knuckles_attackspeed;
}
