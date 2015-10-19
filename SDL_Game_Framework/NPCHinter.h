#ifndef _NPC_HINTER_H_
#define _NPC_HINTER_H_

#include <string>
#include "NPCBase.h"

class NPCHinter : public NPCBase
{
public:
	NPCHinter();
	NPCHinter(const std::string name, const std::string hint);
	NPCHinter(char* img, int cols, int rows, std::string name, std::string hint);
	virtual ~NPCHinter();

	void set_npc_name(const std::string &name);
	const std::string get_npc_name() const;
	void set_npc_hint(const std::string &hint);
	const std::string get_npc_hint();

private:
	std::string m_name;
	std::string m_hint;
};

#endif //_NPC_HINTER_H_
