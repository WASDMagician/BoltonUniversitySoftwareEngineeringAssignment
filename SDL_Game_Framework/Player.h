#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

class Player : 
	public Character
{
public:
	Player();
	Player(char* imgPath, int rows, int cols);
	~Player();
};

#endif

