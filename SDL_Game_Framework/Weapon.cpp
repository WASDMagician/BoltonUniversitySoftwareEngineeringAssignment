#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::Weapon(char* img, int rows, int cols, int value)
	:Pickup_Objects(img, rows, cols, value)
{
}

Weapon::~Weapon()
{
}