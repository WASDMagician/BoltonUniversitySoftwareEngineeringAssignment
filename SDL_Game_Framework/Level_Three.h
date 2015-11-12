#pragma once
#include "Level.h"
class Level_Three :
	public Level
{
public:
	Level_Three();
	Level_Three(std::string name);
	~Level_Three();
	void Setup();
	void Move(int xAmount, int yAmount);
	void Move_Enemies();
};

