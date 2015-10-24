#ifndef _PICKUP_OBJECTS_H_
#define _PICKUP_OBJECTS_H_

#include "Object.h"

class Pickup_Objects :
	public Object
{
public:
	Pickup_Objects();
	~Pickup_Objects();

	bool can_be_pickup_up(); //do we want it to be picked up or not?
	bool place_into_inventory(); //will it go into the inventory if so where?
	bool mouse_pressed(); //pickup using mouse //bb_collison or something here?

private:
};

#endif

