#include "UI.h"

UI::UI() //default constructor
{
	m_collectibles = 0;
	m_health = 100;
	m_ammunition = 15;
	m_name = "Pleb";
}

UI::UI(float items, float health, unsigned int ammo, unsigned int lives, std::string name) // 4 parameter constructor
{
	m_collectibles = items;
	m_health = health;
	m_ammunition = ammo;
	m_name = name;
}

UI::~UI()
{
	//Appropriate memory clean up here
}

bool UI::Display()
{
	return true;
}

bool UI::Flicker()
{
	return true;
}