#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Custom_Types.h"
#include <cstddef>

class Game_Object;

class Transform
{
public:
	Transform();
	~Transform();
	Game_Object *m_p_gameobject;
	bool set_position(float x, float y);
	bool Move(float x = NULL, float y = NULL);
	bool Lerp_To(Vector2 target, float increment, float rangeSnap);
	bool Update_Transform();
	bool Update_World_Position();
	bool Update();

private:
	Vector2 m_target;
	Vector2 m_position;
	float m_increment;
	bool lerping;

	
};

#endif //_TRANSFORM_H_