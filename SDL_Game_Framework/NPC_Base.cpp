// Written by Ed Hawksworth
// Stores the basic information of the friendly npcs in the game
// Specific NPC types will inherit from this, and overload some functions

#include "NPC_Base.h"

NPC_Base::NPC_Base()
	:Character()
{

}

NPC_Base::NPC_Base(char* img, int rows, int cols, int animSpeed)
: Character(img, rows, cols, animSpeed, "")
{

}

bool NPC_Base::Setup(char* imgPath, int rows, int cols, int animationSpeed)
{
	setImage(imgPath, rows, cols);
	return false;
}

NPC_Base::~NPC_Base()
{
}

void NPC_Base::Attack(Character* target)
{
}

void NPC_Base::Defend(Character* target)
{
}

bool NPC_Base::Check_Alive()
{
	return true;
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

bool NPC_Base::set_health(int health)
{
	m_health = health;
	return m_health == health;
}

int NPC_Base::get_health()
{
	return m_health;
}

bool NPC_Base::set_lives(int lives)
{
	m_lives = lives;
	return m_lives == lives;
}

int NPC_Base::get_lives()
{
	return m_lives;
}

bool NPC_Base::set_damage(int damage)
{
	m_damage = damage;
	return m_damage == damage;
}

int NPC_Base::get_damage()
{
	return m_damage;
}

void NPC_Base::set_npc_hint(const std::string &hint)
{
	m_hint = hint;
}

const std::string NPC_Base::get_npc_hint()
{
	return m_hint;
}

bool NPC_Base::React(Character* target)
{
	return false;
}