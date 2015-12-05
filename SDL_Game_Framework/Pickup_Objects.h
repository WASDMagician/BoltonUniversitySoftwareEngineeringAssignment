#ifndef _PICKUP_OBJECTS_H_
#define _PICKUP_OBJECTS_H_

#include "Object.h"

class Pickup_Objects :
	public AW_Sprite_Interface
{
public:
	Pickup_Objects();
	Pickup_Objects(char* imgPath, int rows, int cols, int value);
	~Pickup_Objects();

	void set_value(int value);
	int get_value();

protected:
	int m_value;
};

#endif

