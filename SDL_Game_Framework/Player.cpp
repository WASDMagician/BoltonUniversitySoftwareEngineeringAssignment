// Written by Kyle Thomas - 12/10/15
// Handles certain things for the player eg.
// Setting up the player position, image and name

#include "Player.h"


Player::Player()
:Character("images/player.png", 0, 0, { 0, 0, 0 }, (0, 0, 0), "Player", 100, 10, 5)
{
}

Player::Player(char* img, int rows, int cols, SDL_Colour colour, Transform initial_transform, std::string name, 
unsigned int health, unsigned int defence, unsigned int damage)
:Character(img, rows, cols, colour, initial_transform, name, health, defence, damage)
{
}

Player::~Player()
{
	//Make sure we delete the pointers
}