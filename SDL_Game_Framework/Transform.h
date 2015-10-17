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
	bool set_start_and_end_positions(Vector2 start, Vector2 end, float increment);
	bool Lerp_To(Vector2 target, float increment);
	bool Update();

private:
	bool lerp(Vector2 start, Vector2 end, float increment);

	Vector2 m_position;
	Vector2 m_start_position;
	Vector2 m_end_position;
	float m_increment;

	bool m_b_is_moving;

	
};

#endif //_TRANSFORM_H_