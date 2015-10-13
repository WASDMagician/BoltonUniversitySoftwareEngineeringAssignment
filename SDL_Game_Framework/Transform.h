// Written by Joseph Adams - 14/10/15
// Stores x, y position values along with agle of object
// Used by all visible characters

//Cuts down on code transport and once integrated with AWSprite should be useful

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

class Transform
{
public:
	Transform(float nX = 0.0f, float nY = 0.0f, float nAngle = 0.0f);
	~Transform();

	float x;
	float y;
	float angle;
};

#endif _TRANSFORM_H_

