#ifndef _NPC_HEALER_H_
#define _NPC_HEALER_H_

#include "NPC_Base.h"
class NPC_Healer :
	public NPC_Base
{
public:
	NPC_Healer();
	NPC_Healer(char* img, int rows, int cols, int animSpeed);
	~NPC_Healer();
	virtual bool React(Character* target);
};

#endif
