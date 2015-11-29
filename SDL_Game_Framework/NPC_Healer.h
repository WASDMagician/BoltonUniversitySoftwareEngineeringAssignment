#ifndef _NPC_HEALER_H_
#define _NPC_HEALER_H_

#include "Character.h"
class NPC_Healer :
	public Character
{
public:
	NPC_Healer();
	NPC_Healer(char* img, int rows, int cols, int animSpeed, std::string message);
	~NPC_Healer();
	virtual void React(Character* target);
};

#endif
