#include "Pick_Objects_Factory_Implementation.h"
#include "Pickup_Objects.h"


Pick_Objects_Factory_Implementation::Pick_Objects_Factory_Implementation()
{
}


Pick_Objects_Factory_Implementation::~Pick_Objects_Factory_Implementation()
{
}

Pickup_Objects* Pick_Objects_Factory_Implementation::Make_Object(int type)
{
	switch (type)
	{
	case(COIN) :
		return new Pickup_Objects("images/coin.png", 1, 1, 1, 10);
		break;
	default:
		return NULL;
		break;
	}
}