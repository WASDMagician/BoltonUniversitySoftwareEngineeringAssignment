#include "Character.h"


Character::Character()
{
}

Character::Character(char *img, int x, int y)
{
	set_transparent_colour(255, 0, 255);
	m_get_x = x;
	m_get_y = y;
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
