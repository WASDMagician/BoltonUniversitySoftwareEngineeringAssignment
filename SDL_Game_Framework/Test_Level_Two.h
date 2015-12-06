#ifndef _TEST_LEVEL_TWO_H_
#define _TEST_LEVEL_TWO_H_

#include "Level_Two.h"

//This class exists purely for testing purposes allowing UnitTest++ access to the protected member variables of Level and Level_One
//It should not be used in any game logic, friend class declaration would be preferable but does not work properly with UnitTest++

class Test_Level_Two:
	public Level_Two
{
public:
	Test_Level_Two(Character* player);
	~Test_Level_Two();

	Character* get_player();
	Character_Factory_Implementation* get_character_factory();
	Pick_Objects_Factory_Implementation* get_object_factory();
	Weapon_Factory_Implementation* get_weapon_factory();

	std::vector<AW_Sprite_Interface*>get_areas();
	std::vector<Character*>get_enemies();
	std::vector<Character*>get_npcs();
	std::vector<Pickup_Objects*>get_objects();
	std::vector<Weapon*> get_weapons();
	AW_Sprite_Interface* get_trigger();

	int get_area_offset();

	int get_level_numbe();

	Game_Time *get_time();
	double get_current_time();
	double get_play_time();
	double get_encounter_gap();
	double get_last_encounter_time();
};

#endif //_TEST_LEVEL_ONE_H_