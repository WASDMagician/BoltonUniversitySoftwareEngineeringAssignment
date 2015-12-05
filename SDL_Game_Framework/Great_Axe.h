#ifndef _GREATAXE_H_
#define _GREATAXE_H_

#include "Weapon.h"

class Great_Axe :
	public Weapon
{
public:
	Great_Axe();
	Great_Axe(char* img, int rows, int cols, int value);
	~Great_Axe();
};
#endif