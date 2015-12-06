#include "Test_Level_One.h"

//This class exists purely for testing purposes allowing UnitTest++ access to the protected member variables of Level and Level_One
//It should not be used in any game logic, friend class declaration would be preferable but does not work properly with UnitTest++

Test_Level_One::Test_Level_One(Character *player)
	:Level_One(player)
{
}


Test_Level_One::~Test_Level_One()
{
}

Character* Test_Level_One::get_player()
{
	return m_player;
}

Character_Factory_Implementation* Test_Level_One::get_character_factory()
{
	return m_char_fac;
}

Pick_Objects_Factory_Implementation* Test_Level_One::get_object_factory()
{
	return m_pickup_fac;
}

Weapon_Factory_Implementation* Test_Level_One::get_weapon_factory()
{
	return m_weapon_fac;
}


std::vector<AW_Sprite_Interface*> Test_Level_One::get_areas()
{
	return m_areas;
}

std::vector<Character*>Test_Level_One::get_enemies()
{
	return m_enemies;
}

std::vector<Character*>Test_Level_One::get_npcs()
{
	return m_npcs;
}

std::vector<Pickup_Objects*>Test_Level_One::get_objects()
{
	return m_pickables;
}

std::vector<Weapon*> Test_Level_One::get_weapons()
{
	return m_weapons;
}

AW_Sprite_Interface* Test_Level_One::get_trigger()
{
	return m_level_trigger;
}


int Test_Level_One::get_area_offset()
{
	return m_area_offset;
}


int Test_Level_One::get_level_numbe()
{
	return m_level_number;
}


Game_Time* Test_Level_One::get_time()
{
	return m_timer;
}

double Test_Level_One::get_current_time()
{
	return m_current_time;
}

double Test_Level_One::get_play_time()
{
	return m_play_time;
}

double Test_Level_One::get_encounter_gap()
{
	return m_encounter_gap;
}

double Test_Level_One::get_last_encounter_time()
{
	return m_last_encounter;
}