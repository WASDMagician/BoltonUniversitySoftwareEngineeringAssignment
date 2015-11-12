#include "Crossbow.h"
// Niall -> Crossbow Weakest damage but Normal speed, largest range (bow)

Crossbow::Crossbow()
{
	//default metrics for crossbow
	m_crossbow_damage_modifier = 0.5; // might got to 0.75 here maybe
	m_crossbow_range = 3;
	m_crossbow_attackspeed = 1;
}

Crossbow::Crossbow(char* img, int rows, int cols, int animationSpeed)
:Weapon(img, rows, cols, animationSpeed)
{
}

Crossbow::~Crossbow()
{

}

void Crossbow::set_crossbow_damage(const double damage)
{
	m_crossbow_damage_modifier = damage;
}
const double Crossbow::get_crossbow_damage() const
{
	return m_crossbow_damage_modifier;
}

void Crossbow::set_crossbow_range(const unsigned int range)
{
	m_crossbow_range = range;
}

const unsigned int Crossbow::get_crossbow_range() const
{
	return m_crossbow_range;
}

void Crossbow::set_crossbow_attackspeed(const double atkspd)
{
	m_crossbow_attackspeed = atkspd;
}

const double Crossbow::get_crossbow_attackspeed() const
{
	return m_crossbow_attackspeed;
}

void Crossbow::Render()
{
	update_everything();
}