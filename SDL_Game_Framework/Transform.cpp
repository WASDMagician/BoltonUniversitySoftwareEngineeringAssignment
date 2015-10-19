#include "Transform.h"
#include "Game_Object.h"

Transform::Transform()
:m_current_position(new Vector2{ -1, -1 }), m_increment(-1), m_positions({ { 0, 0 } }), m_target(NULL)
{
	m_positions.push_back(new Vector2{ 0, 0 });
}


Transform::~Transform()
{
}

bool Transform::set_current_position(float x, float y)
{
	m_current_position->x = x;
	m_current_position->y = y;
	Update_World_Position();
	return true;
}


bool Transform::Move(float x, float y)
{
	if (m_p_gameobject != NULL)
	{
		m_p_gameobject->sprite->set_world_position(x, y);
		m_current_position->x = x;
		m_current_position->y = y;
		return true;
	}
	return false;
}

bool Transform::Lerp_To(Vector2 *target, float increment, float rangeSnap = -1)
{	
	float lerp_x = m_current_position->x + (target->x - m_current_position->x) * increment;
	float lerp_y = m_current_position->y + (target->y - m_current_position->y) * increment;

	Move(lerp_x, lerp_y);
	if (rangeSnap != -1)
	{
		if (In_Range(m_current_position, target, rangeSnap))
		{
			Move(target->x, target->y);
			return true;
		}
	}

	
	return false;
}

bool Transform::Update_Transform()
{
	m_current_position->x = m_p_gameobject->sprite->get_x();
	m_current_position->y = m_p_gameobject->sprite->get_y();
	return true;
}

bool Transform::Update_World_Position()
{
	m_p_gameobject->sprite->set_world_position(m_current_position->x, m_current_position->y);
	return true;
}

bool Transform::Update()
{
	return true;
}
