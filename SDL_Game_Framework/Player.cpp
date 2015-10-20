// Written by Kyle Thomas - 12/10/15
// Handles certain things for the player eg.
// Setting up the player position, image and name

#include "Player.h"
#include "UI_Play_Screen.h"


Player::Player()
:Character("images/player.png", 0, 0, "Player", 100, 10, 5)
{
}

Player::Player(char* img, int rows, int cols, std::string name, 
unsigned int health, unsigned int defence, unsigned int damage, unsigned int lives)
: Character(img, rows, cols, name, health, defence, damage), m_lives(lives)
{
}

Player::~Player()
{
	//Make sure we delete the pointers
}

void Player::set_lives(unsigned int lives)
{
	m_lives = lives;
}

unsigned int Player::get_lives()
{
	return m_lives;
}


void Player::update_player_ui()
{
	player_ui->set_health(get_character_health());
	player_ui->set_lives(m_lives);
}