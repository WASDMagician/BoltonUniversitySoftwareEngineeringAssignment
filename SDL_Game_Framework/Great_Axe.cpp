#include "Great_Axe.h"
// Niall -> Greataxe Strongest but Slowest, Normal range (melee)
Great_Axe::Great_Axe()
{
	//default metrics for great_axe
	m_great_axe_damage_modifier = 1.5;
	m_great_axe_range = 1;
	m_great_axe_attackspeed = 0.5;
}

Great_Axe::Great_Axe(char*img, int rows, int cols, int animationSpeed)
:Weapon(img, rows, cols, animationSpeed)
{
}

Great_Axe::~Great_Axe()
{

}

void Great_Axe::set_great_axe_damage(const double damage)
{
	m_great_axe_damage_modifier = damage;
}
const double Great_Axe::get_great_axe_damage() const
{
	return m_great_axe_damage_modifier;
}

void Great_Axe::set_great_axe_range(const unsigned int range)
{
	m_great_axe_range = range;
}

const unsigned int Great_Axe::get_great_axe_range() const
{
	return m_great_axe_range;
}

void Great_Axe::set_great_axe_attackspeed(const double atkspd)
{
	m_great_axe_attackspeed = atkspd;
}

const double Great_Axe::get_great_axe_attackspeed() const
{
	return m_great_axe_attackspeed;
}

void Great_Axe::Render()
{
	update_everything();
}