#ifndef _SWORD_H_
#define _SWORD_H_

#include "Weapon.h"

class Sword :
	public Weapon
{
public:
	Sword();
	Sword(char* img, int x, int y, int animationSpeed, int value);
	~Sword();
};
#endif