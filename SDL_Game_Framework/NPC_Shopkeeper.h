#ifndef _NPC_SHOPKEEPER_H_
#define _NPC_SHOPKEEPER_H_

#include <string>
#include "NPC_Base.h"

class Weapon;

class NPC_Shopkeeper : public NPC_Base
{
public:
	//char* img_path, unsigned int rows, unsigned int cols, string name, unsigned int health, unsigned int damage, unsigned int defence, unsigned animation_speed
	NPC_Shopkeeper();
	virtual ~NPC_Shopkeeper();

	void set_npc_greeting(const std::string &greeting);
	const std::string get_npc_greeting();
	void add_to_shop(int newWeapon, int price);

private:
	std::string m_greeting;
	std::map <int, int> m_stock; //first is the item, second is the price
};

#endif //_NPC_SHOPKEEPER_H_