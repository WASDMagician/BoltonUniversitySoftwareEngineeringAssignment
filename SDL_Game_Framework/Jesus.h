#pragma once
#include "Enemy.h"
class Jesus :
	public Enemy
{
public:
	Jesus();
	Jesus(char* imgPath, int rows, int cols, int animationSpeed);
	~Jesus();
};

