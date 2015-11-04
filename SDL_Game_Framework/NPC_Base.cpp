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