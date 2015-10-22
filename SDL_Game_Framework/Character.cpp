// Written by Kyle Thomas - 12/10/15
// Stores all the information of the characters within the game
// Player and Enemy class will inherit from this

#include "Character.h"

Character::Character()
{

}

Character::Character(creation_variables *initializer)
:Game_Object(initializer->img_path, initializer->cols, initializer->rows), m_name(initializer->name), m_health(initializer->health), m_damage(initializer->damage), 
m_defence(initializer->defence)
{
	sprite->set_auto_animate(initializer->animate_speed);
}

Character::~Character()
{
}

std::string Character::serialize_character()
{
	return "False";
}

