#include "Sword.h"
// Niall -> Sword Normal Damage but fast , Normal Range (melee)

Sword::Sword()
{
	//default metrics for sword
	m_sword_damage_modifier = 1;
	m_sword_range = 1;
	m_sword_attackspeed = 1.5;
}

Sword::Sword(char* img, int rows, int cols)
:Weapon(img, rows, cols)
{
}

Sword::~Sword()
{

}

void Sword::set_sword_damage(const double damage)
{
	m_sword_damage_modifier = damage;
}
const double Sword::get_sword_damage() const
{
	return m_sword_damage_modifier;
}
void Sword::set_sword_range(const unsigned int range)
{
	m_sword_range = range;
}

const unsigned int Sword::get_sword_range() const
{
	return m_sword_range;
}

void Sword::set_sword_attackspeed(const double atkspd)
{
	m_sword_attackspeed = atkspd;
}

const double Sword::get_sword_attackspeed() const
{
	return m_sword_attackspeed;
}