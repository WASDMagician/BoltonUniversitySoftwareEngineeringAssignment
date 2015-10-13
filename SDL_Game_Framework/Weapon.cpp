#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::Weapon(char* img, int x, int y)
:AWSprite(img, 0, 0)
{
	set_world_position((float)x, (float)y);
}

Weapon::~Weapon()
{
}
