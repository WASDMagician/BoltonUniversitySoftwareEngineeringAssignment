#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
:AWSprite(), last_move_x(0), last_move_y(0)
{
	set_transparent_colour(255, 0, 255);
}

AW_Sprite_Interface::AW_Sprite_Interface(char* imgPath, int rows, int cols, int animationSpeed)
: AWSprite(imgPath, rows, cols), last_move_x(0), last_move_y(0)
{
	set_transparent_colour(255, 0, 255);
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
}


void AW_Sprite_Interface::Update()
{
}

void AW_Sprite_Interface::Move_By(int xAmount, int yAmount)
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

void AW_Sprite_Interface::Move_By_Without_Record(int xAmount, int yAmount)
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

void AW_Sprite_Interface::Move_To(int x, int y)
{
	set_world_position(x, y);
}

void AW_Sprite_Interface::Randomize_Position(int xPos, int width, int yPos, int height)
{
	int rand_x = rand() % width;
	int rand_y = rand() % height;
	set_world_position((float)xPos + (float)rand_x, (float)yPos + (float)rand_y);
}

void AW_Sprite_Interface::Revert_Position()
{
	Move_By(-last_move_x, -last_move_y);
}

void AW_Sprite_Interface::Render()
{
	update_everything();
}