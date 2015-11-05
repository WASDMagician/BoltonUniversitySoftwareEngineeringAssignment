// Written by Ed Hawksworth
// Stores the basic information of the friendly npcs in the game
// Specific NPC types will inherit from this, and overload some functions

#include "NPC_Base.h"

NPC_Base::NPC_Base()
{

}

NPC_Base::~NPC_Base()
{
}

bool NPC_Base::set_name(std::string name)
{
	m_name = name;
	return m_name == name;
}

std::string NPC_Base::get_name()
{
	return m_name;
}

bool NPC_Base::set_health(unsigned int health)
{
	m_health = health;
	return m_health == health;
}

unsigned int NPC_Base::get_health()
{
	return m_health;
}

bool NPC_Base::set_lives(unsigned int lives)
{
	m_lives = lives;
	return m_lives == lives;
}

unsigned int NPC_Base::get_lives()
{
	return m_lives;
}

bool NPC_Base::set_damage(unsigned int damage)
{
	m_damage = damage;
	return m_damage == damage;
}

unsigned int NPC_Base::get_damage()
{
	return m_damage;
}

bool NPC_Base::set_defence(unsigned int defence)
{
	m_defence = defence;
	return m_defence == defence;
}

unsigned int NPC_Base::get_defence()
{
	return m_defence;
}

bool NPC_Base::set_points(Vector2 pointA, Vector2 pointB)
{
	m_PointA = pointA;
	m_PointB = pointB;
	return (m_PointA == pointA && m_PointB == pointB);
}

void NPC_Base::move()
{
	this->transform->Move(m_PointA.x, m_PointB.y);
	if (this->transform->get_current_position() == m_PointA && m_Direction)
	{
		m_Direction = !m_Direction;
		this->transform->Lerp_To(&m_PointB, 10.0f, 1.0f);
	}

	if (this->transform->get_current_position() == m_PointB && !m_Direction)
	{
		m_Direction = !m_Direction;
		this->transform->Lerp_To(&m_PointA, 10.0f, 1.0f);
	}
}

std::string NPC_Base::serialize_character()
{
	return "False";
}