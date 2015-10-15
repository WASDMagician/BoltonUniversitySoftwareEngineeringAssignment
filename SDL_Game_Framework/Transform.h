// Written by Joseph Adams - 14/10/15
// Stores x, y position values along with angle of object
// Used by all visible objects

//Cuts down on code transport and once integrated with AWSprite should be useful

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <cstddef>

class Transform
{
public:
	Transform(float nX = 0.0f, float nY = 0.0f);
	~Transform();

	const void set_transform(float x = NULL, float y = NULL);
	Transform* get_transform();

	Transform *m_p_parent = NULL;
	float x;
	float y;
};

#endif _TRANSFORM_H_

