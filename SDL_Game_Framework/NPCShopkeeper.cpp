// Written by Ed Hawksworth
// Class for shopkeeper npcs

#include "NPCShopkeeper.h"

NPCShopkeeper::NPCShopkeeper()
{

}

NPCShopkeeper::NPCShopkeeper(std::string name, std::string greeting)
	:m_name(name), m_greeting(greeting)
{
}

NPCShopkeeper::NPCShopkeeper(char* img, int cols, int rows, std::string name, std::string greeting)
{

}

NPCShopkeeper::~NPCShopkeeper()
{
}

void NPCShopkeeper::set_npc_name(const std::string &name)
{
	m_name = name;
}

const std::string NPCShopkeeper::get_npc_name() const
{
	return m_name;
}

void NPCShopkeeper::set_npc_greeting(const std::string &greeting)
{
	m_greeting = greeting;
}

const std::string NPCShopkeeper::get_npc_greeting()
{
	return m_greeting;
}

void NPCShopkeeper::add_to_shop(int newWeapon, int price)
{
	m_stock.insert(std::pair<int, int>(newWeapon, price));
}