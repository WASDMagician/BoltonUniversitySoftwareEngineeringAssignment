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
	AW_Sprite_Interface(char *img, int rows, int cols, Transform initial_transform);
	virtual ~AW_Sprite_Interface();

	Transform m_transform; //x and y position and angle of the sprite {x, y, angle} //SHOULD THIS BE PRIVATE WITH GET THAT RETURNS REFERENCE?

	Transform* get_parent();

	bool Move();

	bool Update(); //update all attributes and draw
	bool Update_Position(); //update position
	bool Update_Angle(); //update angle

	bool Render(); //draws sprite to screen
};
#endif //_AW_Sprite_Interface_H_

