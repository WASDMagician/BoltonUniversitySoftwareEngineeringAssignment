#ifndef _NPC_BASE_H_
#define _NPC_BASE_H_

#include "Character.h"
#include <string>

class NPC_Base : 
	public Character
{
public:
	NPC_Base();
	NPC_Base(char* img, int rows, int cols, int animSpeed);
	virtual ~NPC_Base();

	virtual bool set_name(std::string name);
	std::string get_name();

	std::string m_name;
	bool set_health(unsigned int health);
	int get_health();

	bool set_lives(unsigned int lives);
	unsigned int get_lives();

	bool set_damage(unsigned int damage);
	unsigned int get_damage();

	bool set_defence(unsigned int defence);
	unsigned int get_defence();

	virtual bool react() = NULL;

	std::string serialize_character();

};

#endif //_NPC_BASE_H_