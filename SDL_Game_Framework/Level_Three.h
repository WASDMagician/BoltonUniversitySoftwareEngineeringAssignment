#pragma once
#include "Level.h"
class Level_Three :
	public Level
{
public:
	Level_Three();
	Level_Three(std::string name, Character* player);
	~Level_Three();
	void Setup();
};

