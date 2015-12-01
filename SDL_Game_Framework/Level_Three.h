#ifndef _LEVEL_THREE_H_
#define _LEVEL_THREE_H_
#include "Level.h"
class Level_Three:
	public Level
{
public:
	Level_Three();
	Level_Three(Character* player);
	~Level_Three();
	void Setup();

	void Move_Enemies();
};

#endif //_LEVEL_THREE_H_