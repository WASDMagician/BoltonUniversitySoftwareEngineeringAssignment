#include "Clown.h"

Clown::Clown()
	:Enemy()
{

}

Clown::Clown(char* imgPath, int rows, int cols, int animationSpeed)
	: Enemy(imgPath, rows, cols, animationSpeed)
{
	set_name("Clown");
}

Clown::~Clown()
{

}