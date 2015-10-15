// Written by Kyle Thomas - 12/10/15
// Stores all the information of the characters within the game
// Player and Enemy class will inherit from this

#include "Character.h"

Character::Character()
{

}

Character::Character(char *img, int rows, int cols, SDL_Colour colour, Transform initial_transform, std::string name,
	unsigned int health, unsigned int damage, unsigned int defence)
	:AW_Sprite_Interface(img, rows, cols, colour, initial_transform), m_name(name), m_health(health), m_damage(damage), m_defence(defence)
{
}

Character::~Character()
{
}

void Character::set_character_name(std::string name)
{
	m_name = name;
}

std::string Character::get_character_name()
{
	return m_name;	
}

void Character::set_character_health(unsigned int health)
{
	m_health = health;
}

unsigned int Character::get_character_health()
{
	return m_health;
}

void Character::set_character_damage(unsigned int damage)
{
	m_damage = damage;
}

unsigned int Character::get_character_damage()
{
	return m_damage;
}

void Character::set_character_defence(unsigned int defence)
{
	m_defence = defence;
}

unsigned int Character::get_character_defence()
{
	return m_defence;
}

