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

void Centipede::Enemy_Roam()
{
	Move_By_Without_Record(rand() % 5 -2, rand() % 5 -2);	
}