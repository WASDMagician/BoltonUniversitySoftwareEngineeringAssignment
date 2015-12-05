#include "Centipede.h"


Centipede::Centipede()
	:Enemy()
{

}

Centipede::Centipede(char* imgPath, int rows, int cols)
	: Enemy(imgPath, rows, cols)
{
}

Centipede::~Centipede()
{

}

void Centipede::Enemy_Movement()
{
	Move_By(rand() % 5 -2, rand() % 5 -2);	
}