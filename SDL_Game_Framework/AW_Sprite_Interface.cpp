#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
:AWSprite(), transform(0, 0, 0)
{

}

AW_Sprite_Interface::AW_Sprite_Interface(char *img, int rows, int cols, SDL_Colour colour, Transform initial_transform)
:AWSprite(img, rows, cols), transform(initial_transform)
{
	set_transparent_colour(colour.r, colour.g, colour.b);
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
}

void AW_Sprite_Interface::Update()
{
	Update_Position();
	Draw();
}

void AW_Sprite_Interface::Update_Position()
{
	set_world_position(transform.x, transform.y); //set world position to transform position
}

void AW_Sprite_Interface::Update_Angle()
{
	setAngle(transform.angle);
}

void AW_Sprite_Interface::Draw()
{
	update_everything();
}