#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
:AWSprite(), m_transform(0, 0)
{

}

AW_Sprite_Interface::AW_Sprite_Interface(char *img, int rows, int cols, Transform initial_transform)
:AWSprite(img, rows, cols), m_transform(initial_transform)
{
	set_transparent_colour(255, 0, 255);
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
}

Transform* AW_Sprite_Interface::get_parent()
{
	return m_transform.m_p_parent;
}

bool AW_Sprite_Interface::Update()
{
	Update_Position();
	Render();
	return false;
}

bool AW_Sprite_Interface::Update_Position()
{
	set_world_position(m_transform.x, m_transform.y); //set world position to transform position
	return false;
}

bool AW_Sprite_Interface::Render()
{
	update_everything();
	return false;
}