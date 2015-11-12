#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
	:AWSprite(), m_current_target(NULL), m_current_position(NULL), m_current_target_index(0), m_patrol_positions(NULL)
{
	m_current_position = new Vector2<int, int>(0, 0);
	Update();
}

AW_Sprite_Interface::AW_Sprite_Interface(char* imgPath, int rows, int cols)
	: AWSprite(imgPath, rows, cols), m_current_target(NULL), m_current_position(NULL), m_current_target_index(0), m_patrol_positions(NULL)
{
	m_current_position = new Vector2<int, int>(0, 0);
	Update();
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
}


void AW_Sprite_Interface::Update()
{
	m_current_position->x = (int)get_x();
	m_current_position->y = (int)get_y();
}

void AW_Sprite_Interface::Render()
{
	update_everything();
}

bool AW_Sprite_Interface::Move_By(int xAmount, int yAmount)
{
	set_world_position_x(get_x() + xAmount);
	set_world_position_y(get_y() + yAmount);
	Update();
	return false;
}

bool AW_Sprite_Interface::Move_To(float x, float y)
{
	set_world_position(x, y);
	Update();
	return false;
}

bool AW_Sprite_Interface::Move_Increment(int x, int y)
{
	set_world_position_x(get_x() + x);
	set_world_position_y(get_y() + y);
	Update();
	return false;
}

bool AW_Sprite_Interface::Lerp_To(Vector2<int, int> *target, double moveSpeed, int rangeSnap)
{
	double lerp_x = get_x() + (target->x - get_x()) / moveSpeed;
	double lerp_y = get_y() + (target->y - get_y()) / moveSpeed;

	Move_To((float)lerp_x, (float)lerp_y);
	if (rangeSnap != -1)
	{
		if (In_Range(m_current_position, target, rangeSnap))
		{
			Move_To((float)target->x, (float)target->y);
			return true;
		}
	}
	return false;
}

bool AW_Sprite_Interface::Move_Between()
{
	Lerp_To(new Vector2<int, int>(2000, 2000), 0.01, 1);
	return true;
	/*if (m_patrol_positions.size() > 0)
	{
		if (m_current_target == NULL)
		{
			printf("m_current_target: %d", m_current_target);
			m_current_target = m_patrol_positions[m_current_target_index];
			printf("m_current_target: %d", m_current_target);
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
	}*/
}

void AW_Sprite_Interface::Add_Patrol_Position(Vector2<int, int> *position)
{
	m_patrol_positions.push_back(position);
	m_current_target = m_patrol_positions[0];
}

void AW_Sprite_Interface::Add_Patrol_Position(std::vector<Vector2<int, int>*>position)
{
	for (auto &p : position)
	{
		m_patrol_positions.push_back(p);
	}
}

void AW_Sprite_Interface::Remove_Patrol_Position(int index)
{
	m_patrol_positions.erase(m_patrol_positions.begin() + index);
}


bool AW_Sprite_Interface::In_Range(Vector2<int, int>*position, Vector2<int, int>*target, int distance)
{
	if (position->x < target->x + distance && position->x > target->x - distance)
	{
		if (position->y < target->y - distance && position->y > target->y + distance)
		{
			return true;
		}
		return false;
	}
	return false; // this true, nothing appears, this false, all enemies are in the top right corner, this was previously not here thus creating a warning "not all paths return a value"
}

Vector2<int, int> *AW_Sprite_Interface::get_current_position()
{
	return m_current_position;
}

void AW_Sprite_Interface::Debug()
{
	printf("AW_Sprite_Debug: \n");
	printf("\tPatrol Positions:\n");
	if (m_patrol_positions.size() > 0)
	{
		for (auto &c : m_patrol_positions)
		{
			printf("\t\tPosition: x: %d  y: %d\n", c->x, c->y);
		}
	}
	printf("\tCurrent position: \n");
	if (m_current_position != NULL)
	{
		printf("\t\tx: %d y: %d\n", m_current_position->x, m_current_position->y);
	}
	
	printf("\tCurrent targe: \n");
	if (m_current_target != NULL)
	{
		printf("\t\tx: %d y:%d\n", m_current_target->x, m_current_target->y);
	}
	system("pause");
}