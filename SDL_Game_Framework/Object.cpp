#include "Object.h"


Object::Object()
:m_name("InstName")
{
}

Object::Object(std::string name)
: m_name(name)
{
}

Object::~Object()
{

}

bool Object::set_obtained(bool obtained)
{
	m_is_obtained = obtained;
	return true;
}

bool Object::get_obtained() // you guys pass judgement on this
{
	return m_is_obtained;
}

bool Object::set_glowing(bool glowing)
{
	m_is_glowing = glowing;
	return true;
}

bool Object::get_glowing() // just an idea
{
	return m_is_glowing;
}