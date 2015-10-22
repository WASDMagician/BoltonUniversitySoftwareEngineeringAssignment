#include "Transform.h"
#include "Game_Object.h"

Transform::Transform()
:m_current_position(new Vector2{ -1, -1 }), m_increment(-1), m_target(NULL), current_target_position(0)
{
	m_position_list.push_back(new Vector2({ 0, 0 }));
	m_position_list.push_back(new Vector2({ 0, 400 }));
	m_position_list.push_back(new Vector2({ 400, 400}));
	m_position_list.push_back(new Vector2({ 400, 0}));
	//m_position_list.push_back(new Vector2({ 400, 200 }));
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

Vector2& Transform::get_current_position()
{
	return *m_current_position;
}


bool Transform::Move(float x, float y)
{
	if (m_p_gameobject != NULL)
	{
		set_current_position(x, y);
		return true;
	}
	return false;
}

bool Transform::Increment_Move(float x, float y)
{
	if (m_p_gameobject != NULL)
	{
		m_p_gameobject->sprite->set_world_position_x(m_p_gameobject->sprite->get_x() + x);
		m_p_gameobject->sprite->set_world_position_y(m_p_gameobject->sprite->get_y() + y);
		m_current_position->x = x;
		m_current_position->y = y;
	}
	return false;
}

bool Transform::Move_Between()
{
	if (m_target == NULL)
	{
		m_target = m_position_list[current_target_position];
	}
	if (Lerp_To(m_target, 20, 1))
	{
		if (current_target_position + 1 >= m_position_list.size())
		{
			current_target_position = 0;
		}
		else
		{
			current_target_position++;
		}
		m_target = m_position_list[current_target_position];
	}
	return false;
}

bool Transform::Lerp_To(Vector2 *target, float increment, float rangeSnap = -1)
{	
	float lerp_x = m_current_position->x + (target->x - m_current_position->x) / increment;
	float lerp_y = m_current_position->y + (target->y - m_current_position->y) / increment;

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
