// Written by Kyle Thomas - 12/10/15
// Handles certain things for the player eg.
// Setting up the player position, image and name

#include "Player.h"


Player::Player()
{
	character = new Character("images/player.png", 0, 0, "Player"); // Create the player
	m_health = 100; // Set the starting health
	m_damage = 10; // Set the starting damage
	m_defence = 5; // Set the starting defence
}


Player::~Player()
{
	//Make sure we delete the pointers
	delete character;
	character = NULL;
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