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

}

bool Transform::set_start_and_end_positions(Vector2 start, Vector2 end, float increment)
{
	if (start == end)
	{
		m_b_is_moving;
	}
}

bool Transform::Update()
{
	if (m_start_position == m_end_position)
	{
		m_b_is_moving = false;
	}
}
