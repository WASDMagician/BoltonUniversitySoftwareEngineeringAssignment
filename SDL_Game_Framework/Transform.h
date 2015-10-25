#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <math.h>
#include <vector>
#include <cstddef>

#include "Custom_Types.h"

class Game_Object;

class Transform
{
public:
	Transform();
	~Transform();
	Game_Object *m_p_gameobject;

	bool set_current_position(float x, float y);
	Vector2 &get_current_position();

	bool Add_Position(Vector2 *position);
	bool Add_Position(std::vector<Vector2*> positions);

	bool Move(float x = NULL, float y = NULL);
	bool Increment_Move(float x = NULL, float y = NULL);
	bool Move_Between();
	bool Lerp_To(Vector2 *target, float increment, float rangeSnap);

	bool Update_Transform();
	bool Update_World_Position();
	bool Update();

private:
	Vector2 *m_current_position;
	float m_increment;

	std::vector<Vector2*>m_position_list;
	Vector2 *m_target;
	unsigned int current_target_position;
	
};

#endif //_TRANSFORM_H_