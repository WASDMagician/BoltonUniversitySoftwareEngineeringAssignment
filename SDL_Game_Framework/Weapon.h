#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Pickup_Objects.h"
class Weapon :
	public Pickup_Objects
{
public:
	Weapon();
	Weapon(char* img, int rows, int cols, int m_value);
	~Weapon();
};

#endif //_WEAPON_H_