#include "Character.h"

Character::Character()
	:AW_Sprite_Interface()
{
}

Character::Character(char* imgPath, int rows, int cols, int animationSpeed)
	:AW_Sprite_Interface(imgPath, rows, cols)
{
}

Character::~Character()
{
}