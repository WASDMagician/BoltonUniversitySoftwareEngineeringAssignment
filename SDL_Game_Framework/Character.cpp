// Written by Kyle Thomas - 12/10/15
// Stores all the information of the characters within the game
// Player and Enemy class will inherit from this

#include "Character.h"

Character::Character()
{

}

Character::Character(std::string name,
	const unsigned int health, const unsigned int damage, const unsigned int defence)
	:m_name(name), m_health(health), m_damage(damage), m_defence(defence)
{
}

Character::Character(char* img, int cols, int rows, std::string name, unsigned int health, unsigned int damage, unsigned int defence)
:Game_Object(img, cols, rows), m_name(name), m_health(health), m_damage(damage), m_defence(defence)
{

}

Character::~Character()
{
}

void Character::set_character_name(const std::string &name)
{
	m_name = name;
}

const std::string Character::get_character_name() const
{
	return m_name;	
}

void Character::set_character_health(const unsigned int health)
{
	m_health = health;
}

const unsigned int Character::get_character_health() const
{
	return m_health;
}

void Character::set_character_damage(const unsigned int damage)
{
	m_damage = damage;
}

const unsigned int Character::get_character_damage() const
{
	return m_damage;
}

void Character::set_character_defence(const unsigned int defence)
{
	m_defence = defence;
}

const unsigned int Character::get_character_defence() const
{
	return m_defence;
}

std::string Character::serialize_character()
{

}

