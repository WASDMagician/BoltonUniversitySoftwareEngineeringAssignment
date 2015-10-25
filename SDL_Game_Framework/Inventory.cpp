#include "Inventory.h"


Inventory::Inventory()
{
}

Inventory::Inventory(char *img, int rows, int columns)
{
	new_inv = new AWSprite(img, 1, 1);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			new_inv->set_world_position(250, 500);
			inv_sprite.push_back(new_inv);
		}
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
	new_inv->update_everything();
	
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			//inv_sprite[i][j].update_everything();
			std::cout << "made a change" << std::endl; // CAN DELETE THIS LINE OFCOURSE
		}
	}
	return false;
}


