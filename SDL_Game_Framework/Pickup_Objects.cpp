#include "Pickup_Objects.h"


Pickup_Objects::Pickup_Objects()
{
}


Pickup_Objects::~Pickup_Objects()
{
}

bool Pickup_Objects::can_be_pickup_up()
{
	return true;
}

bool Pickup_Objects::place_into_inventory()
{
	return true;
}

bool Pickup_Objects::mouse_pressed()
{
	return true;
}