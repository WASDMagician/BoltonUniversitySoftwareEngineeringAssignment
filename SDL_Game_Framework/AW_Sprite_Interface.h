#ifndef _AW_Sprite_Interface_H_
#define _AW_Sprite_Interface_H_

#include <iostream>

#include "AWSprite.h"
#include "Transform.h"

class AW_Sprite_Interface :
	public AWSprite
{
public:
	AW_Sprite_Interface();
	AW_Sprite_Interface(char *img, int rows, int cols, SDL_Colour transparent_colour, Transform initial_transform);
	~AW_Sprite_Interface();

	Transform transform; //x and y position and angle of the sprite {x, y, angle} //SHOULD THIS BE PRIVATE WITH GET THAT RETURNS REFERENCE?

	void Update(); //update all attributes and draw
	void Update_Position(); //update position
	void Update_Angle(); //update angle

	void Draw(); //draws sprite to screen
};
#endif //_AW_Sprite_Interface_H_

