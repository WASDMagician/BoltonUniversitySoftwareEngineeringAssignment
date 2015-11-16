#ifndef _NPC_HINTER_H_
#define _NPC_HINTER_H_

#include <string>
#include "NPC_Base.h"

class NPC_Hinter : public NPC_Base
{
public:
	//char* img_path, unsigned int rows, unsigned int cols, string name, unsigned int health, unsigned int damage, unsigned int defence, unsigned animation_speed
	NPC_Hinter();
	NPC_Hinter(char* img, int rows, int cols, int animSpeed);
	~NPC_Hinter();

	void set_npc_hint(const std::string &hint);
	const std::string get_npc_hint();
	bool react();

private:
	std::string m_hint;
};

#endif //_NPC_HINTER_H_