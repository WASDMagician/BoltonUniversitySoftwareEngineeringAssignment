#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "AW_Sprite_Interface.h"
class Weapon :
	public AW_Sprite_Interface
{
public:
	Weapon();
	Weapon(char* img, int rows, int cols, int animationSpeed);
	~Weapon();
	virtual void Render() = 0;
};

#endif //_WEAPON_H_