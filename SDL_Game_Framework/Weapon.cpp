#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::Weapon(weapon_constructor_variables *initialiser)
:Game_Object(new game_object_constructor_variables{initialiser->img_path, initialiser->rows, initialiser->cols})
{
}

Weapon::~Weapon()
{
}
