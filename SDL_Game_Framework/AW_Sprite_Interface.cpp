#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
:AWSprite(), m_current_target(NULL), m_current_position(NULL), m_current_target_index(0), m_patrol_positions(NULL), last_move_x(0), last_move_y(0)
{
	m_current_position = new Vector2<float, float>(0, 0);
	Update();
}

AW_Sprite_Interface::AW_Sprite_Interface(char* imgPath, int rows, int cols, int animationSpeed)
: AWSprite(imgPath, rows, cols), m_current_target(NULL), m_current_position(NULL), m_current_target_index(0), m_patrol_positions(NULL), last_move_x(0), last_move_y(0)
{
	m_current_position = new Vector2<float, float>(0, 0);
	Update();
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
	for (int i = 0; i < m_patrol_positions.size(); i++)
	{
		delete m_patrol_positions[i];
	}
	m_patrol_positions.clear();

	delete m_current_position;
	delete m_current_target;
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

bool AW_Sprite_Interface::set_target(AW_Sprite_Interface *target)
{
	m_current_target = target->get_current_position();
	return m_current_target == target->get_current_position();
}

int AW_Sprite_Interface::get_distance_between(AW_Sprite_Interface* target)
{
	int x_dist = target->get_current_position()->x -  m_current_position->x;
	int y_dist = target->get_current_position()->y - m_current_position->y;
	return (x_dist * x_dist + y_dist * y_dist);
}

void AW_Sprite_Interface::Move_By(int xAmount, int yAmount)
{
	set_world_position_x(get_x() + xAmount);
	set_world_position_y(get_y() + yAmount);
	last_move_x = xAmount;
	last_move_y = yAmount;
	Update();
}

bool AW_Sprite_Interface::Move_To(float x, float y)
{
	set_world_position(x, y);
	Update();
	return (get_x() == x && get_y() == y);
}

void AW_Sprite_Interface::Move_Toward_Target()
{
	float x_diff = m_current_target->x - get_x();
	float y_diff = m_current_target->y - get_y();
	float angle = atan2(x_diff, y_diff) * 180 / 3.14;

	float nx = 2 * cos(angle);
	float ny = 2 * sin(angle);
	Move_By(nx, ny);
}

void AW_Sprite_Interface::Add_Patrol_Position(Vector2<float, float> *position)
{
	m_patrol_positions.push_back(position);
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

void AW_Sprite_Interface::Revert_Position()
{
	m_current_position->x = -last_move_x;
	m_current_position->y = -last_move_y;
	Move_By(-last_move_x, -last_move_y);
}