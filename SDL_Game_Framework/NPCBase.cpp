// Written by Ed Hawksworth
// Stores the basic information of the friendly npcs in the game
// Specific NPC types will inherit from this, and overload some functions

#include "NPCBase.h"

NPCBase::NPCBase()
{

}

NPCBase::NPCBase(std::string name)
	:m_name(name)
{
}

NPCBase::NPCBase(char* img, int cols, int rows, std::string name)
	: Game_Object(img, cols, rows), m_name(name)
{

}

NPCBase::~NPCBase()
{
}

void NPCBase::set_npc_name(const std::string &name)
{
	m_name = name;
}

const std::string NPCBase::get_npc_name() const
{
	return m_name;
}