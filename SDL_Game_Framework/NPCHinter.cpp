// Written by Ed Hawksworth
// Class for hint giving NPC(s)

#include "NPCHinter.h"

NPCHinter::NPCHinter()
{

}

NPCHinter::NPCHinter(std::string name, std::string hint)
	:m_name(name), m_hint(hint)
{
}

NPCHinter::NPCHinter(char* img, int cols, int rows, std::string name, std::string hint)
{

}

NPCHinter::~NPCHinter()
{
}

void NPCHinter::set_npc_name(const std::string &name)
{
	m_name = name;
}

const std::string NPCHinter::get_npc_name() const
{
	return m_name;
}

void NPCHinter::set_npc_hint(const std::string &hint)
{
	m_hint = hint;
}

const std::string NPCHinter::get_npc_hint()
{
	return m_hint;
}