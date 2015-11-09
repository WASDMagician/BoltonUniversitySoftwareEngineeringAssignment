#ifndef _CLOWN_H_
#define _CLOWN_H_

#include "Enemy.h"

class Clown :
	public Enemy
{
public:
	Clown();
	Clown(char* imgPath, int rows, int cols, int animationSpeed);
	~Clown();
};
#endif
