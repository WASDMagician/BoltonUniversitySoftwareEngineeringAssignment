#ifndef _LEVEL_ONE_H_
#define _LEVEL_ONE_H_
#include "Level.h"

class Level_One :
	public Level
{
public:
	Level_One();
	Level_One(Character* player);
	~Level_One();
	void Setup();
};

#endif //_LEVEL_ONE_H_