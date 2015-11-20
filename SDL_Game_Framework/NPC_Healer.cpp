#include "NPC_Healer.h"


NPC_Healer::NPC_Healer()
{

}

NPC_Healer::NPC_Healer(char* img, int rows, int cols, int animSpeed)
	: NPC_Base(img, rows, cols, animSpeed)
{

}

NPC_Healer::~NPC_Healer()
{
}

bool NPC_Healer::React(Character* target)
{
	target->set_health(10);
	return true;
}