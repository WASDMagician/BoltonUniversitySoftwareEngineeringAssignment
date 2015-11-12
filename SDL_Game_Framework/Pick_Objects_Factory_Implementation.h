#ifndef _PICK_OBJECTS_FACTORY_IMPLEMENTATION_H_
#define _PICK_OBJECTS_FACTORY_IMPLEMENTATION_H_

#include "Pick_Objects_Factory.h"

enum TYPES { COIN };

class Pick_Objects_Factory_Implementation :
	public Pick_Objects_Factory
{
public:
	Pick_Objects_Factory_Implementation();
	~Pick_Objects_Factory_Implementation();

	Pickup_Objects *Make_Object(int type);
};

#endif //_PICK_OBJECTS_FACTORY_IMPLEMENTATION_H_