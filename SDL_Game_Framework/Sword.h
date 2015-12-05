#ifndef _SWORD_H_
#define _SWORD_H_

#include "Weapon.h"

class Sword :
	public Weapon
{
public:
	Sword();
	Sword(char* img, int cols, int rows, int value);
	~Sword();
};
#endif