// Written by Ed Hawksworth
// Class for hint giving NPC(s)

#include "NPC_Hinter.h"

NPC_Hinter::NPC_Hinter()
{

}


NPC_Hinter::~NPC_Hinter()
{
}

void NPC_Hinter::set_npc_hint(const std::string &hint)
{
	m_hint = hint;
}

const std::string NPC_Hinter::get_npc_hint()
{
	return m_hint;
}

bool NPC_Hinter::react()
{
	std::cout << m_hint << "\n"; //should be with strange magic shit
	return false;
}