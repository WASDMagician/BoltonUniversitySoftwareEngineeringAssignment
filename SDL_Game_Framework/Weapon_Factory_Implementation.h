#pragma once
#include "Weapon_Factory.h"

#include "Weapon.h"
#include <vector>

enum WEAPON_TYPES { CROSSBOW, EMPOWERED_KNUCKLES, GREAT_AXE, SNIPER, SWORD };

class Weapon_Factory_Implementation :
	public Weapon_Factory
{
public:
	Weapon_Factory_Implementation();
	~Weapon_Factory_Implementation();

	Weapon* Make_Weapon(int weaponType);

private:
	std::vector<char*>IMAGES;
};

