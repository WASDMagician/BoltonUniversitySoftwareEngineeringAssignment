#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
:AWSprite(0, 0)
{
	set_transparent_colour(255, 0, 255);
}

AW_Sprite_Interface::AW_Sprite_Interface(char* img, unsigned int rows, unsigned int cols)
: AWSprite(img, rows, cols, false)
{
	set_transparent_colour(255, 0, 255);
}


AW_Sprite_Interface::~AW_Sprite_Interface()
{
}
