#ifndef _WEAPON_H_
#define _WEAPON_H_

struct weapon_constructor_variables
{
	char* img_path;
	unsigned int rows;
	unsigned int cols;
};

#include "Game_Object.h"
class Weapon :
	public Game_Object
{
public:
	Weapon();
	Weapon(weapon_constructor_variables *initialiser);
	~Weapon();
};

#endif //_WEAPON_H_