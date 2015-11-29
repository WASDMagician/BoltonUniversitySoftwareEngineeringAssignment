#include "Sword.h"
// Niall -> Sword Normal Damage but fast , Normal Range (melee)

Sword::Sword()
{
}

Sword::Sword(char* img, int rows, int cols, int animationSpeed, int value)
:Weapon(img, rows, cols, animationSpeed, value)
{
}

Sword::~Sword()
{

}