// Written by Ed Hawksworth
// Class for shopkeeper npcs

#include "NPC_Shopkeeper.h"

NPC_Shopkeeper::NPC_Shopkeeper()
{
}

NPC_Shopkeeper::~NPC_Shopkeeper()
{
}

void NPC_Shopkeeper::set_npc_greeting(const std::string &greeting)
{
	m_greeting = greeting;
}

const std::string NPC_Shopkeeper::get_npc_greeting()
{
	return m_greeting;
}

void NPC_Shopkeeper::add_to_shop(int newWeapon, int price)
{
	m_stock.insert(std::pair<int, int>(newWeapon, price));
}

bool NPC_Shopkeeper::react()
{
	std::cout << m_hint << "\n"; //should be with strange magic shit
}