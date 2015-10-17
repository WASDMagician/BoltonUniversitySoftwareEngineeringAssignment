#include "Object.h"


Object::Object()
{
	m_xPos = 0;
	m_yPos = 0;
	m_name = "My Precious Shiny ";
}

Object::Object(float x, float y, std::string name)
{
	m_xPos = x;
	m_yPos = y;
	m_name = name;
}

Object::~Object()
{

}

bool Object::IsObtained() // you guys pass judgement on this
{
	if (m_is_obtained = true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Object::IsGlowing() // just an idea
{
	if (m_is_obtained == true)
	{
		m_is_glowing = false;
	}
	else
	{
		m_is_glowing = true;
	}
	return true;
}