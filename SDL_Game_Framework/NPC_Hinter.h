#ifndef _NPC_HINTER_H_
#define _NPC_HINTER_H_

#include <string>
#include "Character.h"

class NPC_Hinter : 
	public Character
{
public:
	NPC_Hinter();
	NPC_Hinter(char* img, int rows, int cols, std::string message);
	~NPC_Hinter();
};

#endif //_NPC_HINTER_H_