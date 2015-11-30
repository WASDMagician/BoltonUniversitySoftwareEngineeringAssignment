#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <vector>
#include "Character_Factory_Implementation.h"
#include "Pick_Objects_Factory_Implementation.h"
#include "Weapon_Factory_Implementation.h"
#include "AW_Sprite_Interface.h"
#include "Character.h"
#include "Pickup_Objects.h"

class Level
{
public:
	Level();
	//@update_UML
	Level(std::string name, Character* player);
	virtual ~Level();
	bool set_level_name(std::string name);
	std::string get_level_name();
	AW_Sprite_Interface* get_trigger();
	std::vector<AW_Sprite_Interface*>get_areas();
	std::vector<Character*>get_enemies();
	std::vector<Character*>get_npcs();
	std::vector<Pickup_Objects*>get_pickables();
	std::vector<Weapon*>get_weapons();

	//@update_uml
	bool Run_Level_Logic(float xAmount, float yAmount);

	void Move_All(int xAmount, int yAmount);
	template<typename T>
	void Move(int xAmount, int yAmount, std::vector<T>inputVector);

	bool Perform_Enemy_Encounter();
	void Perform_Coin_Collision();
	void Perform_Weapon_Collision();
	void Perform_NPC_Encounter();

	//@update_uml
	void Reset_All_Positions();
	template<typename T>
	void Reset_Positions(std::vector<T>inputVector);

	void Render_All();
	template<typename T>
	void Render(std::vector<T>inputVector);

protected:
	Character *m_player;

	Character_Factory_Implementation *m_char_fac;
	Pick_Objects_Factory_Implementation *m_pickup_fac;
	Weapon_Factory_Implementation *m_weapon_fac;
	std::vector<AW_Sprite_Interface*>m_areas;
	std::vector<Character*>m_enemies;
	std::vector<Character*>m_npcs;
	std::vector<Pickup_Objects*>m_pickables;
	std::vector<Weapon*> m_weapons;
	AW_Sprite_Interface* m_level_trigger; 

	std::string m_level_name;

	Game_Time *m_timer;
	double m_current_time;
	double m_play_time;
	double m_encounter_gap;
	double m_last_encounter;


};

#endif //_LEVEL_H_