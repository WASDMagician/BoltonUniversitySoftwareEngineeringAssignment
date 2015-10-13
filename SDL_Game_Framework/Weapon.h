#pragma once
#include "AWSprite.h"
class Weapon :
	public AWSprite
{
public:
	Weapon();
	Weapon(char* img, int x, int y);
	~Weapon();
};

