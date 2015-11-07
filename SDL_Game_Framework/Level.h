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
	virtual ~Level();

	virtual void Setup() = 0;
	virtual void Move(int xAmount, int yAmount) = 0;
	void Render();

protected:
	std::vector<AW_Sprite_Interface*>m_areas;
	std::vector<Character*>m_enemies;


};

#endif //_LEVEL_H_