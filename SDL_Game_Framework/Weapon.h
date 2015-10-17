#pragma once
#include "Game_Object.h"
class Weapon :
	public Game_Object
{
public:
	Weapon();
	Weapon(char* img, int rows, int cols);
	~Weapon();
};

