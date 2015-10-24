#ifndef _NPC_BASE_H_
#define _NPC_BASE_H_

#include <string>
#include "Character.h"

class NPC_Base : public Character
{
public:
	NPC_Base(character_creation_variables *initialiser);
	virtual ~NPC_Base();

	bool set_name(std::string name);
	std::string get_name();

	bool set_health(unsigned int health);
	unsigned int get_health();

	bool set_lives(unsigned int lives);
	unsigned int get_lives();

	bool set_damage(unsigned int damage);
	unsigned int get_damage();

	bool set_defence(unsigned int defence);
	unsigned int get_defence();

	std::string serialize_character();

private:
};

#endif //_NPC_BASE_H_