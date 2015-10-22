#ifndef _NPC_BASE_H_
#define _NPC_BASE_H_

#include <string>
#include "Character.h"

class NPC_Base : public Character
{
public:
	NPC_Base(creation_variables *initialiser);
	virtual ~NPC_Base();

	void set_npc_name(const std::string &name);
	const std::string get_npc_name() const;

private:
	std::string m_name;
};

#endif //_NPC_BASE_H_