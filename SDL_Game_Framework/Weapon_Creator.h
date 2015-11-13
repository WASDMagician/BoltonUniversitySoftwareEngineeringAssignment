#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Object.h"

class Weapon_Creator :
	public AW_Sprite_Interface
{
public:
	Weapon_Creator();
	Weapon_Creator(char* imgPath, int rows, int cols, int animationSpeed);
	~Weapon_Creator();

	bool set_can_be_picked(bool pickable); //do we want it to be picked up or not?
	bool get_can_be_picked();

	void Render();


private:
	std::string m_name;
	bool m_b_can_be_picked_up;
};

#endif // _WEAPON_H_
