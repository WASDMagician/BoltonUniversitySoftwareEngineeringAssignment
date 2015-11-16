#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
	:AWSprite(), m_current_target(NULL), m_current_position(NULL), m_current_target_index(0), m_patrol_positions(NULL)
{
	m_current_position = new Vector2<float, float>(0, 0);
	Update();
}

AW_Sprite_Interface::AW_Sprite_Interface(char* imgPath, int rows, int cols, int animationSpeed)
	: AWSprite(imgPath, rows, cols), m_current_target(NULL), m_current_position(NULL), m_current_target_index(0), m_patrol_positions(NULL)
{
	m_current_position = new Vector2<float, float>(0, 0);
	Update();
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

int AW_Sprite_Interface::get_angle_between(AW_Sprite_Interface* target)
{
	int x_diff = (int)target->get_x() - (int)get_x();
	int y_diff = (int)target->get_y() - (int)get_y();
	return atan2(x_diff, y_diff) * 180 / 3.14;
}

int AW_Sprite_Interface::get_distance_between(AW_Sprite_Interface* target)
{
	int x_dist = (int)target->get_current_position()->x - (int)m_current_position->x;
	int y_dist = (int)target->get_current_position()->y - (int)m_current_position->y;
	return (x_dist * x_dist + y_dist * y_dist);
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

bool AW_Sprite_Interface::Move_Increment(float x, float y)
{
	set_world_position_x(get_x() + x);
	set_world_position_y(get_y() + y);
	Update();
	return false;
}

bool AW_Sprite_Interface::Lerp_To(Vector2<float, float> *target, double moveSpeed, int rangeSnap)
{
	int lerp_x = (int)get_x() + ((int)target->x - (int)get_x()) / 1;
	int lerp_y = (int)get_y() + ((int)target->y - (int)get_y()) / 2;

	printf("%d %d\n", lerp_x, lerp_y); //@debug

	Move_By((int)get_x() + lerp_x, (int)get_y() + lerp_y);
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
	Lerp_To(new Vector2<float, float>(500, 500), 0.01, 1);
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

void AW_Sprite_Interface::Add_Patrol_Position(Vector2<float, float> *position)
{
	m_patrol_positions.push_back(position);
	m_current_target = m_patrol_positions[0];
}

void AW_Sprite_Interface::Add_Patrol_Position(std::vector<Vector2<float, float>*>position)
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
	return false; // this true, nothing appears, this false, all enemies are in the top right corner, this was previously not here thus creating a warning "not all paths return a value"
}

Vector2<float, float> *AW_Sprite_Interface::get_current_position()
{
	return m_current_position;
}

void AW_Sprite_Interface::Randomize_Position(int xPos, int width, int yPos, int height)
{
	int rand_x = rand() % width;
	int rand_y = rand() % height;
	set_world_position((float)xPos + (float)rand_x, (float)yPos + (float)rand_y);
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