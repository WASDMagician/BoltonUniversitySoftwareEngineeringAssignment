#pragma once
#include "Level.h"
class Level_One :
	public Level
{
public:
	Level_One();
	~Level_One();

	void Setup();
	void Move(int xAmount, int yAmount);
};

