#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <vector>
#include "AW_Sprite_Interface.h"

const int NUM_GAME_OBJECTS = 20;

class Inventory 
{
public:
	Inventory();
	Inventory(char *img, int rows, int columns); //uses char img to setup the UI image
	~Inventory();

	bool remove_item();
	bool add_item(int item_type);
	bool work();

	bool Draw();
private:
	int m_row[1];
	int m_column[9];
	AW_Sprite_Interface m_item;

	std::vector<AW_Sprite_Interface> inv_items;
	std::vector<std::vector<AW_Sprite_Interface*>> inv_sprite;

	float m_inv_bar_left_x;
	float m_inv_bar_top_y;
	float m_inv_bar_x_margin;
	float m_inv_bar_y_margin;

	bool is_slot_taken;
};

#endif