#include "CrossBow.h"
// Niall -> CrossBow Weakest damage but Normal speed, largest range (bow)

CrossBow::CrossBow()
{
	//default metrics for crossbow
	m_crossbow_damage_modifier = 0.5; // might got to 0.75 here maybe
	m_crossbow_range = 3;
	m_crossbow_attackspeed = 1;
}

CrossBow::CrossBow(char* img, int x, int y)
:Weapon(img, 0, 0)
{
	set_world_position((float)x, (float)y);
}

CrossBow::~CrossBow()
{

}

void CrossBow::set_crossbow_damage(const double damage)
{
	m_crossbow_damage_modifier = damage;
}
const double CrossBow::get_crossbow_damage() const
{
	return m_crossbow_damage_modifier;
}

void CrossBow::set_crossbow_range(const unsigned int range)
{
	m_crossbow_range = range;
}

const unsigned int CrossBow::get_crossbow_range() const
{
	return m_crossbow_range;
}

void CrossBow::set_crossbow_attackspeed(const double atkspd)
{
	m_crossbow_attackspeed = atkspd;
}

const double CrossBow::get_crossbow_attackspeed() const
{
	return m_crossbow_attackspeed;
}