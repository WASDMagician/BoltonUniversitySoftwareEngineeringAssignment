// Written by Kyle Thomas - 12/10/15
// Handles certain things for the player eg.
// Setting up the player position, image and name

#include "Player.h"
#include "UI_Play_Screen.h"


Player::Player(character_creation_variables* initialisers)
:Character(initialisers)
{
}


Player::~Player()
{
	//Make sure we delete the pointers
}

bool Player::set_name(std::string name)
{
	m_name = name;
	return m_name == name;
}

std::string Player::get_name()
{
	return m_name;
}

bool Player::set_health(unsigned int health)
{
	m_health = health;
	return m_health == health;
}

unsigned int Player::get_health()
{
	return m_health;
}

bool Player::set_lives(unsigned int lives)
{
	m_lives = lives;
	return m_lives == lives;
}

unsigned int Player::get_lives()
{
	return m_lives;
}

bool Player::set_damage(unsigned int damage)
{
	m_damage = damage;
	return m_damage == damage;
}

unsigned int Player::get_damage()
{
	return m_damage;
}

bool Player::set_defence(unsigned int defence)
{
	m_defence = defence;
	return m_defence == defence;
}

unsigned int Player::get_defence()
{
	return m_defence;
}

void Player::update_player_ui()
{
	player_ui->set_health(get_health());
	player_ui->set_lives(m_lives);
}

std::string Player::serialize_character()
{
	return "False";
}