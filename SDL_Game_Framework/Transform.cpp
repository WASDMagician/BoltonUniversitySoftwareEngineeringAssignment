#include "Transform.h"
#include "Game_Object.h"

Transform::Transform()
:m_position({ -1, -1 }), m_increment(-1), lerping(false)
{
}


Transform::~Transform()
{
}

bool Transform::set_position(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
	Update_World_Position();
	return true;
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

bool Transform::Lerp_To(Vector2 target, float increment, float rangeSnap = -1)
{
	//the higher the increment the SLOWER the movement will be
	float lerp_x = m_position.x + (target.x - m_position.x) * increment;
	float lerp_y = m_position.y + (target.y - m_position.y) * increment;

	Move(lerp_x, lerp_y);
	if (rangeSnap != -1)
	{
		if (In_Range(m_position, target, rangeSnap))
		{
			Move(target.x, target.y);
		}
	}

	
	return false;
}

bool Transform::Update_Transform()
{
	m_position.x = m_p_gameobject->sprite->get_x();
	m_position.y = m_p_gameobject->sprite->get_y();
}

bool Transform::Update_World_Position()
{
	m_p_gameobject->sprite->set_world_position(m_position.x, m_position.y);
	return true;
}

bool Transform::Update()
{
}
