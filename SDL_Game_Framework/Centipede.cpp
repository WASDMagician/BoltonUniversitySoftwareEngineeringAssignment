#include "Centipede.h"


Centipede::Centipede()
	:Enemy()
{

}

Centipede::Centipede(char* imgPath, int rows, int cols, int animationSpeed)
	: Enemy(imgPath, rows, cols, animationSpeed)
{
	enemy_state = ROAMING;
}

Centipede::~Centipede()
{

}

bool Centipede::Enemy_Roam()
{
	if (enemy_state == ROAMING)
	{
		Move_By(rand() % 5 -2, rand() % 5 -2);
		return true;
	}

	return false;
}