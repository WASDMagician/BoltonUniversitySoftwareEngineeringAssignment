#include "Ogre.h"


Ogre::Ogre()
{
	//Base values for Ogre enemy
	//Can be changed at any time
	m_enemy_name = "Ogre";
	m_enemy_health = 20;
	m_enemy_damage = 10;
	m_enemy_defence = 5;
}

Ogre::Ogre(std::string enemy_name, int enemy_health, int enemy_damage, int enemy_defence)
{
	ogre_enemy = new Enemy("images/ogre.png", 1, 1, enemy_name, enemy_health, enemy_damage, enemy_defence);
}

Ogre::~Ogre()
{
}

std::string Ogre::get_enemy_name()
{
	return m_enemy_name;
}

int Ogre::get_enemy_health()
{
	return m_enemy_health;
}

int Ogre::get_enemy_damage()
{
	return m_enemy_damage;
}

int Ogre::get_enemy_defence()
{
	return m_enemy_defence;
}
