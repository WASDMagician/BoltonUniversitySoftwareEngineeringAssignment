#ifndef _AW_SPRITE_INTERFACE_H_
#define _AW_SPRITE_INTERFACE_H_

#include "AWSprite.h"
class AW_Sprite_Interface :
	public AWSprite
{
public:
	AW_Sprite_Interface();
	AW_Sprite_Interface(char *img, unsigned int rows, unsigned int cols);
	~AW_Sprite_Interface();
};

#endif //_AW_SPRITE_INTERFACE_