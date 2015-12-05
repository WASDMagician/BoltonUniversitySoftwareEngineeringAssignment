// Written by Kyle Thomas - 12/10/15
// Handles certain things for the player eg.
// Setting up the player position, image and name

#include "Player.h"
#include "UI_Play_Screen.h"


Player::Player()
:Character()
{
}

Player::Player(char* imgPath, int rows, int cols)
: Character(imgPath, rows, cols, "")
{
}

Player::~Player()
{
}