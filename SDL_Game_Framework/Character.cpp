// Written by Kyle Thomas - 12/10/15
// Stores all the information of the characters within the game
// Player and Enemy class will inherit from this

#include "Character.h"

Character::Character()
{

}

Character::Character(char *img, int rows, int cols, Transform trans, std::string name)
:AWSprite(img, rows, cols), m_name(name), character_transform(trans)
{
	set_transparent_colour(255, 0, 255);
}

Character::~Character()
{
}

std::string Character::get_character_name()
{
	return m_name;	
}