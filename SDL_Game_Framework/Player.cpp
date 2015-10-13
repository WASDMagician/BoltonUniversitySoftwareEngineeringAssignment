// Written by Kyle Thomas - 12/10/15
// Handles certain things for the player eg.
// Setting up the player position, image and name

#include "Player.h"


Player::Player()
:Character("images/player.png", 0, 0, "Player"), m_health(100), m_damage(10), m_defence(5)
{
}

Player::Player(char* img, int x, int y, std::string name, unsigned int health, unsigned int defence, unsigned int damage)
:Character(img, x, y, name), m_health(health), m_defence(defence), m_damage(damage)
{
}

Player::~Player()
{
	//Make sure we delete the pointers
}

int Player::get_health()
{
	return m_health;
}

int Player::get_defence()
{
	return m_defence;
}

int Player::get_damage()
{
	return m_damage;
}