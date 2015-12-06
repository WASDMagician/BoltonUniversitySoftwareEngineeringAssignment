#include "Pickup_Objects.h"


Pickup_Objects::Pickup_Objects()
	:m_value(0)
{
}

Pickup_Objects::Pickup_Objects(char* imgPath, int rows, int cols, int value)
	: AW_Sprite_Interface(imgPath, rows, cols), m_value(value)
{

}

Pickup_Objects::~Pickup_Objects()
{
}

void Pickup_Objects::set_value(int value)
{
	m_value = value;
}

int Pickup_Objects::get_value()
{
	return m_value;
}