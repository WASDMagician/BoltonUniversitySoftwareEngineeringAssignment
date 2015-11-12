#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::Weapon(char* img, int rows, int cols, int animationSpeed)
	:AW_Sprite_Interface(img, rows, cols, animationSpeed)
{
}

Weapon::~Weapon()
{
}
