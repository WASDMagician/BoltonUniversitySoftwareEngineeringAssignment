#include "Weapon_Factory_Implementation.h"
#include "Weapon.h"
#include "Crossbow.h"
#include "Empowered_Knuckles.h"
#include "Great_Axe.h"
#include "Sniper.h"
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
	case(CROSSBOW) :
		return new Crossbow("images/jesus.bmp", 1, 1, 1);
		break;
	case(EMPOWERED_KNUCKLES) :
		return new Empowered_Knuckles("images/jesus.bmp", 1, 1, 1);
		break;
	case(GREAT_AXE) :
		return new Great_Axe("images/pickaxe.bmp", 12, 1, 100);
		break;
	case(SNIPER):
		return new Sniper("images/jesus.bmp", 1, 1, 1);
		break;
	case(SWORD) :
		return new Sword("images/swords.bmp", 8, 1, 1);
		break;
	default:
		return NULL;
	}
}
