#ifndef _NPC_BASE_H_
#define _NPC_BASE_H_

#include <string>
#include "Game_Object.h"

class NPCBase : public Game_Object
{
public:
	NPCBase();
	NPCBase(const std::string name);
	NPCBase(char* img, int cols, int rows, std::string name);
	virtual ~NPCBase();

	void set_npc_name(const std::string &name);
	const std::string get_npc_name() const;

private:
	std::string m_name;
};

#endif //_NPC_BASE_H_
