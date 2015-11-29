#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::Weapon(char* img, int rows, int cols, int animationSpeed, int value)
	:Pickup_Objects(img, rows, cols, animationSpeed, value)
{
}

Weapon::~Weapon()
{
}