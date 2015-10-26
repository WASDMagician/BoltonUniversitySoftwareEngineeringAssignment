// Written by Kyle Thomas - 12/10/15
// Stores all the information of the characters within the game
// Player and Enemy class will inherit from this

#include "Character.h"

Character::Character()
	:m_health(0), m_damage(0), m_defence(0), m_img_path(""), m_cols(0), m_rows(0), m_animation_speed(0), m_type("")
{
}

Character::Character(creation_variables *initializer)
:Game_Object(initializer->img_path, initializer->cols, initializer->rows), m_name(initializer->name), 
m_health(initializer->health), m_damage(initializer->damage), m_defence(initializer->defence), m_img_path(initializer->img_path),
m_cols(initializer->cols), m_rows(initializer->rows), m_animation_speed(initializer->animate_speed), m_type(initializer->type)
{
	sprite->set_auto_animate(initializer->animate_speed);
}

Character::~Character()
{
}

std::string Character::serialize_character()
{
	std::cout << std::endl;
	m_serial += m_type + " ";
	m_serial += m_name + " ";
	m_serial += to_string(m_health) + " ";
	m_serial += to_string(m_damage) + " ";
	m_serial += to_string(m_defence) + " ";
	m_serial += std::string(m_img_path) + " ";
	m_serial += to_string(m_rows) + " ";
	m_serial += to_string(m_cols) + " ";
	m_serial += to_string(m_animation_speed);
	m_serial += to_string(sprite->get_x()) + " ";
	m_serial += to_string(sprite->get_y()) + " ";
	std::cout << m_serial << std::endl;
	return m_serial;
}

bool Character::render()
{
	sprite->auto_animate();
	sprite->update_everything();
	return true;
}

