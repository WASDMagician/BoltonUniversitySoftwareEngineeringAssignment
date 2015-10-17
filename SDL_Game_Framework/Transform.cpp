#include "Transform.h"
#include "Game_Object.h"

Transform::Transform()
{
}


Transform::~Transform()
{
}

bool Transform::set_position(float x, float y)
{
	
}

bool Transform::Move(float x, float y)
{
	if (m_p_gameobject != NULL)
	{
		m_p_gameobject->sprite->set_world_position(x, y);
		m_position.x = x;
		m_position.y = y;
		return true;
	}
	return false;
}

bool Transform::set_start_and_end_positions(Vector2 start, Vector2 end, float increment)
{
	if (start == end)
	{
		m_b_is_moving;
	}
}

bool Transform::Lerp_To(Vector2 target, float increment)
{
	//the higher the increment the SLOWER the movement will be
	float lerp_x = m_position.x + (target.x - m_position.x) / increment;
	float lerp_y = m_position.y + (target.y - m_position.y) / increment;
	
	Move(lerp_x, lerp_y);
	return true;
}

bool Transform::Update()
{
	if (m_start_position == m_end_position)
	{
		m_b_is_moving = false;
	}
}
