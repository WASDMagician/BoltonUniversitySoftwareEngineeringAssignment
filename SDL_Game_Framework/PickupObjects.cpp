#include "PickupObjects.h"


PickupObjects::PickupObjects()
{
}


PickupObjects::~PickupObjects()
{
}

bool PickupObjects::can_be_pickup_up()
{
	return true;
}

bool PickupObjects::place_into_inventory()
{
	return true;
}

bool PickupObjects::mouse_pressed()
{
	return true;
}