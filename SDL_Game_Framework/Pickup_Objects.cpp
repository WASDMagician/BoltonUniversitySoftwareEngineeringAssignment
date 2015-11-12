#include "Pickup_Objects.h"


Pickup_Objects::Pickup_Objects()
{
}

Pickup_Objects::Pickup_Objects(char* imgPath, int rows, int cols, int animationSpeed)
:AW_Sprite_Interface(imgPath, rows, cols, animationSpeed)
{

}

Pickup_Objects::~Pickup_Objects()
{
}

bool Pickup_Objects::set_name(std::string name)
{ 
	m_name = name;
	return m_name == name;
}

std::string Pickup_Objects::get_name()
{
	return m_name;
}

bool Pickup_Objects::set_can_be_picked(bool pickable)
{
	m_b_can_be_picked_up = pickable;
	return m_b_can_be_picked_up == pickable;
}

bool Pickup_Objects::get_can_be_picked()
{
	return m_b_can_be_picked_up;
}

void Pickup_Objects::Render()
{
	update_everything();
}