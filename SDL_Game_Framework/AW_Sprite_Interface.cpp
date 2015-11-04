#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
	:AWSprite()
{

}

AW_Sprite_Interface::AW_Sprite_Interface(char* imgPath, int rows, int cols)
	:AWSprite(imgPath, rows, cols)
{
	
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
}


void AW_Sprite_Interface::Update()
{
	m_current_position->x = get_x();
	m_current_position->y = get_y();
}

void AW_Sprite_Interface::Render()
{
	update_everything();
}

bool AW_Sprite_Interface::Move_To(float x, float y)
{
	set_world_position(x, y);
	return false;
}

bool AW_Sprite_Interface::Move_Increment(float x, float y)
{
	set_world_position_x(get_x() + x);
	set_world_position_y(get_y() + y);
	return false;
}

bool AW_Sprite_Interface::Lerp_To(Vector2<float, float> *target, int moveSpeed, int rangeSnap)
{
	float lerp_x = get_x() + (target->x - get_x()) / moveSpeed;
	float lerp_y = get_y() + (target->y - get_y()) / moveSpeed;

	Move_To(lerp_x, lerp_y);
	if (rangeSnap != -1)
	{
		if (In_Range(m_current_position, target, rangeSnap))
		{
			Move_To(target->x, target->y);
			return true;
		}
	}
	return false;
}

bool AW_Sprite_Interface::Move_Between()
{
	if (m_patrol_positions.size() > 0)
	{
		if (m_current_target == NULL)
		{
			m_current_target = m_patrol_positions[m_current_target_index];
		}
		if (Lerp_To(m_current_position, 20, 1))
		{
			if (m_current_target_index + 1 >= m_patrol_positions.size())
			{
				m_current_target_index = 0;
			}
			else
			{
				m_current_target_index++;
			}
			m_current_target = m_patrol_positions[m_current_target_index];
		}
		return true;
	}
	else
	{

		return false;
	}
}

void AW_Sprite_Interface::Add_Patrol_Position(Vector2<float, float> *position)
{
	m_patrol_positions.push_back(position);
}

void AW_Sprite_Interface::Add_Patrol_Position(std::vector<Vector2<float, float>*>position)
{
	for (int i = 0; i < position.size(); i++)
	{
		m_patrol_positions.push_back(position[i]);
	}
}

void AW_Sprite_Interface::Remove_Patrol_Position(int index)
{
	m_patrol_positions.erase(m_patrol_positions.begin() + index);
}


//this may not work, check at earliest opportunity
bool AW_Sprite_Interface::In_Range(Vector2<float, float>*position, Vector2<float, float>*target, int distance)
{
	if (position->x < target->x + distance && position->x > target->x - distance)
	{
		if (position->y < target->y - distance && position->y > target->y + distance)
		{
			return true;
		}
		return false;
	}
}