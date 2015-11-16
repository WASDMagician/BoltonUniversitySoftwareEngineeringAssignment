#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <vector>
#include "Character_Factory_Implementation.h"
#include "Pick_Objects_Factory_Implementation.h"
#include "Weapon_Factory_Implementation.h"
#include "AW_Sprite_Interface.h"
#include "Character.h"
#include "Pickup_Objects.h"
#include "Vector2.h"

class Level
{
public:
	Level();
	Level(std::string name);
	virtual ~Level();
	bool set_level_name(std::string name);
	std::string get_level_name();
	AW_Sprite_Interface* get_trigger();
	std::vector<Character*>get_enemies();
	std::vector<Character*>get_npcs();
	std::vector<Pickup_Objects*>get_pickables();
	std::vector<Weapon*>get_weapons();
	void Move(int xAmount, int yAmount);
	void Render();

protected:
	Character_Factory_Implementation *char_fac;
	Pick_Objects_Factory_Implementation *pickup_fac;
	Weapon_Factory_Implementation *weapon_fac;
	std::vector<AW_Sprite_Interface*>m_areas;
	std::vector<Character*>m_enemies;
	std::vector<Character*>m_npcs;
	std::vector<Pickup_Objects*>m_pickables;
	std::vector<Weapon*> m_weapons;
	AW_Sprite_Interface* level_trigger; 

	std::string m_level_name;


};

#endif //_LEVEL_H_