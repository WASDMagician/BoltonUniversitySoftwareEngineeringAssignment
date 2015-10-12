// Written by Kyle Thomas - 12/10/15
// Stores all the information of the characters within the game
// Player and Enemy class will inherit from this

#include "Character.h"


Character::Character()
{
}

Character::Character(char *img, int x, int y, std::string name)
{
	set_transparent_colour(255, 0, 255);
	m_get_x = x;
	m_get_y = y;
	m_name = name;
}

Character::~Character()
{
}

int Character::get_x()
{
	return m_get_x;
}

int Character::get_y()
{
	return m_get_y;
}

std::string Character::get_name()
{
	return m_name;
}