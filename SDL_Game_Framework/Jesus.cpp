#include "Jesus.h"


Jesus::Jesus()
	:Enemy()
{
}


Jesus::Jesus(char* imgPath, int rows, int cols, int animationSpeed)
	: Enemy(imgPath, rows, cols, animationSpeed)
{
}

Jesus::~Jesus()
{
}
