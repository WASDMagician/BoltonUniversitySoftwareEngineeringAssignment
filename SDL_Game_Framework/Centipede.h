#ifndef _CENTIPEDE_H_
#define _CENTIPEDE_H_

#include "Enemy.h"

class Centipede :
	public Enemy
{
public:
	Centipede();
	Centipede(char* imgPath, int rows, int cols, int animationSpeed);
	~Centipede();
	virtual bool Enemy_Roam();
};
#endif
