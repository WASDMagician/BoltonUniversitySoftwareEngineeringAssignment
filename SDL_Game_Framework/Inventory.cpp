#include "Inventory.h"


Inventory::Inventory()
	:m_inv_bar_left_x(250), m_inv_bar_top_y(500), m_inv_bar_x_margin(40), m_inv_bar_y_margin(40)
{
}

Inventory::Inventory(char *img, int rows, int columns)
	: m_inv_bar_left_x(250), m_inv_bar_top_y(500), m_inv_bar_x_margin(45), m_inv_bar_y_margin(45)
{
	for (int i = 0; i < rows; i++)
	{
		std::vector<AW_Sprite_Interface*>new_row;
		inv_sprite.push_back(std::vector<AW_Sprite_Interface*>());
		for (int j = 0; j < columns; j++)
		{
			AW_Sprite_Interface *new_sprite = new AW_Sprite_Interface(img, 1, 1);
			new_sprite->set_world_position(m_inv_bar_left_x + (j * m_inv_bar_x_margin), m_inv_bar_top_y + (i * m_inv_bar_y_margin));
			new_row.push_back(new_sprite);
		}
		inv_sprite.push_back(new_row);
	}
}

Inventory::~Inventory()
{
}

bool Inventory::add_item(int item_id)
{
	inv_items.push_back(m_item);
	//possible for loop
	if (!is_slot_taken) //need to figure out a better way to implement something like this
	{
		//add_item(item* m_item) //something like this perhaps?
		return true;
	}
	return false;
}

bool Inventory::remove_item()
{
	//possible loop to erase a specific item
	inv_items.erase(inv_items.begin());
	return true;
}

bool Inventory::work()
{
	return true;
}

bool Inventory::Draw()
{	
	for (unsigned int i = 0; i < inv_sprite.size(); i++)
	{
		for (unsigned int j = 0; j < inv_sprite[i].size(); j++)
		{
			inv_sprite[i][j]->update_everything();
		}
		
	}
	return false;
}


