#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <vector>
#include "Character_Factory_Implementation.h"
#include "AW_Sprite_Interface.h"
#include "Character.h"
#include "Vector2.h"

class Level
{
public:
	Level();
	Level(std::string name);
	virtual ~Level();
	virtual void Move(int xAmount, int yAmount) = 0;
	virtual void Move_Enemies() = 0;
	bool set_level_name(std::string name);
	std::string get_level_name();
	AW_Sprite_Interface* get_trigger();
	void Render();

protected:
	Character_Factory_Implementation *char_fac;
	std::vector<AW_Sprite_Interface*>m_areas;
	std::vector<Character*>m_enemies;
	AW_Sprite_Interface* level_trigger; 

	std::string m_level_name;


};

#endif //_LEVEL_H_