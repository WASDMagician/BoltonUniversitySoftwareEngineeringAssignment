#include "Inventory.h"


Inventory::Inventory()
{
}

Inventory::Inventory(char *img, int rows, int columns)
{
	m_row = rows;
	m_column[9] = columns;
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


