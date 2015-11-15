#pragma once
#include "Level.h"
class Level_Two :
	public Level
{
public:
	Level_Two();
	Level_Two(std::string name);
	~Level_Two();
	void Setup();
};

