#ifndef _PICK_OBJECTS_FACTORY_H_
#define _PICK_OBJECTS_FACTORY_H_

class Pickup_Objects;

class Pick_Objects_Factory
{
public:
	virtual Pickup_Objects* Make_Object(int type) = 0;
	
};

#endif //_PICK_OBJECTS_FACTORY_H_