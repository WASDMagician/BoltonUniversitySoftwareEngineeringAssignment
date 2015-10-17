#pragma once
#include "AWSprite.h"
class AW_Sprite_Interface :
	public AWSprite
{
public:
	AW_Sprite_Interface();
	AW_Sprite_Interface(char *img, unsigned int rows, unsigned int cols);
	~AW_Sprite_Interface();
};

