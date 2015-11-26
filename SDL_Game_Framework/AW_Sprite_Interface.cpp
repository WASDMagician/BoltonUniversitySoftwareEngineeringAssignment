#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
:AWSprite(), last_move_x(0), last_move_y(0), target_position_x(NULL), target_position_y(NULL), has_target(false), spawn_x(NULL), spawn_y(NULL)
{
	set_transparent_colour(255, 0, 255);
}

AW_Sprite_Interface::AW_Sprite_Interface(char* imgPath, int rows, int cols, int animationSpeed)
: AWSprite(imgPath, rows, cols), last_move_x(0), last_move_y(0), target_position_x(NULL), target_position_y(NULL), has_target(false), spawn_x(NULL), spawn_y(NULL)
{
	set_transparent_colour(255, 0, 255);
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
}


void AW_Sprite_Interface::Update()
{
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
	float xDiff = target_position_x - get_x();
	float yDiff = target_position_y - get_y();

	float angle = atan2(yDiff, xDiff);
	
	Move_By((5 * (cos(angle))), (5 * (sin(angle))));
}

bool AW_Sprite_Interface::In_Range(float range)
{
	printf("%f\n", target_position_x - range);
	return(get_x() > target_position_x - range && get_x() < target_position_x + range && get_y() > target_position_y - range && get_y() < target_position_y + range);
}



void AW_Sprite_Interface::Set_Target_Position(float x, float y) 
{
	target_position_x = x;
	target_position_y = y;
	has_target = true;
}

void AW_Sprite_Interface::Update_Target_Position(float x, float y)
{
	target_position_x += x;
	target_position_y += y;
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
}

void AW_Sprite_Interface::Render()
{
	update_everything();
}