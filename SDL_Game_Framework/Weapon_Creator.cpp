#include "Weapon_Creator.h"


Weapon_Creator::Weapon_Creator()
{
}

Weapon_Creator::Weapon_Creator(char* imgPath, int rows, int cols, int animationSpeed)
	:AW_Sprite_Interface(imgPath, rows, cols, animationSpeed)
{

}
Weapon_Creator::~Weapon_Creator()
{
}

bool Weapon_Creator::set_can_be_picked(bool pickable)
{
	m_b_can_be_picked_up = pickable;
	return m_b_can_be_picked_up == pickable;
}

bool Weapon_Creator::get_can_be_picked()
{
	return m_b_can_be_picked_up;
}

void Weapon_Creator::Render()
{
	update_everything();
}
