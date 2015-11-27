#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
	:AWSprite(), last_move_x(0), last_move_y(0), target({NULL, NULL}), has_target(false), spawn_x(NULL), spawn_y(NULL)
{
	set_transparent_colour(255, 0, 255);
}

AW_Sprite_Interface::AW_Sprite_Interface(char* imgPath, int rows, int cols, int animationSpeed)
	: AWSprite(imgPath, rows, cols), last_move_x(0), last_move_y(0), target({NULL, NULL}), has_target(false), spawn_x(NULL), spawn_y(NULL)
{
	set_transparent_colour(255, 0, 255);
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
}


void AW_Sprite_Interface::Update()
{
}

void AW_Sprite_Interface::Add_Position(position pos)
{
	positions.push_back(pos);
}

void AW_Sprite_Interface::Add_Positions(std::vector<position> newPositions)
{
	for (size_t i = 0; i < newPositions.size(); i++)
	{
		positions.push_back(newPositions[i]);
	}
}

void AW_Sprite_Interface::Clear_Positions()
{
	positions.clear();
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
	float currentX = get_x();
	float currentY = get_y();

	float moveX = (float)xAmount;
	float moveY = (float)yAmount;

	float newX = currentX + moveX;
	float newY = currentY + moveY;

	set_world_position_x(newX);
	set_world_position_y(newY);

	last_move_x = xAmount;
	last_move_y = yAmount;
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
	float xDiff = target.x - get_x();
	float yDiff = target.y - get_y();

	float angle = atan2(yDiff, xDiff);
	
	Move_By((5 * (cos(angle))), (5 * (sin(angle))));
}

bool AW_Sprite_Interface::In_Range(float range)
{
	return(get_x() > target.x - range && get_x() < target.x + range && get_y() > target.y - range && get_y() < target.y + range);
}

void AW_Sprite_Interface::Increment_Target()
{
	if (In_Range(50))
	{
		set_target_position(current_target_index + 1);
	}
}

void AW_Sprite_Interface::set_target_position(int targetIndex)
{
	if (targetIndex < positions.size())
	{
		target = positions[targetIndex];
		current_target_index = targetIndex;
	}
	else
	{
		target = positions[0];
		current_target_index = 0;
	}
	has_target = true;
}

void AW_Sprite_Interface::set_target_position(position targ) 
{
	target = targ;
	has_target = true;
}

void AW_Sprite_Interface::Update_Target_Position(int xAmount, int yAmount)
{
	target.x += xAmount;
	target.y += yAmount;
	for (size_t i = 0; i < positions.size(); i++)
	{
		positions[i].x += xAmount;
		positions[i].y += yAmount;
	}
}

bool AW_Sprite_Interface::Has_Target()
{
	return has_target;
}

void AW_Sprite_Interface::set_spawn(float x, float y)
{
	spawn_x = x;
	spawn_y = y;
}

void AW_Sprite_Interface::Move_To_Spawn()
{
	set_world_position_x(spawn_x);
	set_world_position_y(spawn_y);
}

void AW_Sprite_Interface::Randomize_Position(float xPos, float width, float yPos, float height)
{
	float rand_x = rand() % (int)width;
	float rand_y = rand() % (int)height;
	set_world_position(xPos + rand_x, yPos + rand_y);
}

void AW_Sprite_Interface::Revert_Position()
{
	Move_By(-last_move_x, -last_move_y);
	Update_Target_Position(-last_move_x, -last_move_y);
}

void AW_Sprite_Interface::Render()
{
	update_everything();
}