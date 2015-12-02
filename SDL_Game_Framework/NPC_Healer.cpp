#include "NPC_Healer.h"


NPC_Healer::NPC_Healer()
{

}

NPC_Healer::NPC_Healer(char* img, int rows, int cols, int animSpeed, std::string message)
	: Character(img, rows, cols, animSpeed, message)
{

}

NPC_Healer::~NPC_Healer()
{
}

void NPC_Healer::React(Character* target)
{
	if (target->get_health() < 100)
	{
		
		target->set_health(100);
	}
}