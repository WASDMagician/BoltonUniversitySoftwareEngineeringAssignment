#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <vector>
#include "AWSprite.h"
#include "Game_Object.h"

const int NUM_GAME_OBJECTS = 20;

class Inventory :
	public AWSprite
{
public:
	Inventory();
	Inventory(char *img, int rows, int columns); //uses char img to setup the UI image
	~Inventory();

	bool remove_item();
	bool add_item(int item_type);
	bool work();
private:
	int m_row;
	int m_column[9];
	Game_Object m_item;
	std::vector<Game_Object> inv_items;

	bool is_slot_taken;
};

#endif

