#ifndef _PICKUP_OBJECTS_H_
#define _PICKUP_OBJECTS_H_

#include "Object.h"

class Pickup_Objects :
	public AW_Sprite_Interface
{
public:
	Pickup_Objects();
	Pickup_Objects(char* imgPath, int rows, int cols, int animationSpeed);
	~Pickup_Objects();

	bool set_name(std::string name);
	std::string get_name();

	bool set_can_be_picked(bool pickable); //do we want it to be picked up or not?
	bool get_can_be_picked();

	void Render();
	

private:
	std::string m_name;
	bool m_b_can_be_picked_up;
};

#endif

