#ifndef _WEAPON_FACTORY_H_
#define _WEAPON_FACTORY_H_

class Weapon;

class Weapon_Factory
{
public:
	virtual Weapon* Make_Weapon(int weapon_type) = 0;

};

#endif //_WEAPON_FACTORY_H_