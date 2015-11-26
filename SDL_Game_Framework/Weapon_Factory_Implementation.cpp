#include "Weapon_Factory_Implementation.h"
#include "Weapon.h"
#include "Great_Axe.h"
#include "Sword.h"


Weapon_Factory_Implementation::Weapon_Factory_Implementation()
{
}


Weapon_Factory_Implementation::~Weapon_Factory_Implementation()
{
}

Weapon* Weapon_Factory_Implementation::Make_Weapon(int weaponType)
{
	switch (weaponType)
	{
	case(GREAT_AXE) :
		return new Great_Axe("images/pickaxe.bmp", 12, 1, 100);
		break;
	case(SWORD) :
		return new Sword("images/swords.bmp", 8, 1, 1);
		break;
	default:
		return NULL;
	}
}
