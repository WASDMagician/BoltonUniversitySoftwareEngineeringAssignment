#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
	:AWSprite(), m_last_move_x(0), m_last_move_y(0), m_target({NULL, NULL}), m_has_target(false), 
	m_spawn_x(NULL), m_spawn_y(NULL), m_current_target_index(0), m_positions(NULL), m_player_timer(NULL)
{
	set_transparent_colour(255, 0, 255);
	m_player_timer = new Game_Time();
}

AW_Sprite_Interface::AW_Sprite_Interface(char* imgPath, int rows, int cols, int animationSpeed)
	: AWSprite(imgPath, rows, cols), m_last_move_x(0), m_last_move_y(0), m_target({NULL, NULL}), 
	m_has_target(false), m_spawn_x(NULL), m_spawn_y(NULL), m_current_target_index(0), m_positions(NULL),
	m_player_timer(NULL)
{
	set_transparent_colour(255, 0, 255);
	m_player_timer = new Game_Time();
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
}


void AW_Sprite_Interface::Update()
{
}

void AW_Sprite_Interface::Add_Position(position pos)
{
	m_positions.push_back(pos);
	m_spawn_positions = m_positions;
}

void AW_Sprite_Interface::Add_Positions(std::vector<position> newPositions)
{
	for (size_t i = 0; i < newPositions.size(); i++)
	{
		m_positions.push_back(newPositions[i]);
	}
	m_spawn_positions = m_positions;
}

void AW_Sprite_Interface::Clear_Positions()
{
	m_positions.clear();
}

//template<typename T>
bool AW_Sprite_Interface::Is_Contained(std::vector<AW_Sprite_Interface*>vectorInput, position testPos)
{
	bool is_contained = false;

	float player_left = get_x();
	float player_right = get_x() + get_width();
	float player_top = get_y();
	float player_bottom = get_y() + get_height();

	for (size_t i = 0; i < vectorInput.size(); i++)
	{
		float input_left = vectorInput[i]->get_x() + testPos.x;
		float input_right = vectorInput[i]->get_x() + testPos.x + vectorInput[i]->get_width();
		float input_top = vectorInput[i]->get_y() + testPos.y;
		float input_bottom = vectorInput[i]->get_y() + testPos.y + vectorInput[i]->get_height();
		
		if (input_left <= player_left && input_right >= player_right && input_top <= player_top && input_bottom >= player_bottom)
		{
			is_contained = true;
			break;
		}
	}
	return is_contained;
}

void AW_Sprite_Interface::Move_By(float xAmount, float yAmount)
{
	float moveX = get_x() + (xAmount);
	float moveY = get_y() + (yAmount);

	set_world_position_x(moveX);
	set_world_position_y(moveY);

	m_last_move_x = xAmount;
	m_last_move_y = yAmount;
}

void AW_Sprite_Interface::Move_By_Without_Record(float xAmount, float yAmount)
{
	float currentX = get_x();
	float currentY = get_y();

	float moveX = (float)xAmount;
	float moveY = (float)yAmount;

	float newX = currentX + moveX;
	float newY = currentY + moveY;

	set_world_position_x(newX);
	set_world_position_y(newY);
}

void AW_Sprite_Interface::Move_To(float x, float y)
{
	set_world_position(x, y);
}

void AW_Sprite_Interface::Move_Toward()
{
	float xDiff = m_target.x - get_x();
	float yDiff = m_target.y - get_y();

	float angle = atan2(yDiff, xDiff);
	SDL_Delay(1);
	Move_By((10 * (cos(angle))), (10 * (sin(angle))));
}

bool AW_Sprite_Interface::In_Range(float range)
{
	return(get_x() > m_target.x - range && get_x() < m_target.x + range && get_y() > m_target.y - range && get_y() < m_target.y + range);
}

void AW_Sprite_Interface::Increment_Target()
{
	if (In_Range(50))
	{
		set_target_position(m_current_target_index + 1);
	}
}

void AW_Sprite_Interface::set_target_position(int targetIndex)
{
	if (targetIndex < m_positions.size())
	{
		m_target = m_positions[targetIndex];
		m_current_target_index = targetIndex;
	}
	else
	{
		m_target = m_positions[0];
		m_current_target_index = 0;
	}
	m_has_target = true;
}

void AW_Sprite_Interface::set_target_position(position targ) 
{
	m_target = targ;
	m_has_target = true;
}

void AW_Sprite_Interface::Update_Target_Position(float xAmount, float yAmount)
{
	m_target.x += xAmount;
	m_target.y += yAmount;
	for (size_t i = 0; i < m_positions.size(); i++)
	{
		m_positions[i].x += xAmount;
		m_positions[i].y += yAmount;
	}
}

bool AW_Sprite_Interface::Has_Target()
{
	return m_has_target;
}

void AW_Sprite_Interface::set_spawn(float x, float y)
{
	m_spawn_x = x;
	m_spawn_y = y;
}

void AW_Sprite_Interface::Move_To_Spawn()
{
	set_world_position_x(m_spawn_x);
	set_world_position_y(m_spawn_y);
	m_positions = m_spawn_positions;
}

void AW_Sprite_Interface::Randomize_Position(float xPos, float width, float yPos, float height)
{
	float rand_x = rand() % (int)(width - get_width());
	float rand_y = rand() % (int)(height - get_height());

	set_world_position(xPos + rand_x, yPos + rand_y);
}

void AW_Sprite_Interface::Revert_Position()
{
	Move_By(-m_last_move_x, -m_last_move_y);
	Update_Target_Position(-m_last_move_x, -m_last_move_y);
}

void AW_Sprite_Interface::Render()
{
	update_everything();
}