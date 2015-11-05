#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::Weapon(char* img, int rows, int cols)
	:AW_Sprite_Interface(img, rows, cols)
{
}

Weapon::~Weapon()
{
}
