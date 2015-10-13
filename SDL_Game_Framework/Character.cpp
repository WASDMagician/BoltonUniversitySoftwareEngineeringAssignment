// Written by Kyle Thomas - 12/10/15
// Stores all the information of the characters within the game
// Player and Enemy class will inherit from this

#include "Character.h"

Character::Character()
{

}

Character::Character(char *img, int x, int y, std::string name)
:AWSprite(img, x, y), m_name(name)
{
}

Character::~Character()
{
}

std::string Character::get_character_name()
{
	return m_name;
}
