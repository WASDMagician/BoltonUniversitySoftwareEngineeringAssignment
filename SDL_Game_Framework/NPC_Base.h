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

	virtual bool Setup(char* imgPath, int rows, int cols, int animationSpeed);
	virtual void Update();
	virtual void Render();
	virtual void Attack(Character* target);
	virtual void Defend(Character* target);
	virtual bool Check_Health();

	virtual bool set_name(std::string name);
	virtual std::string get_name();

	std::string m_name;
	virtual bool set_health(unsigned int health);
	virtual int get_health();

	virtual bool set_lives(unsigned int lives);
	virtual unsigned int get_lives();

	virtual bool set_damage(unsigned int damage);
	virtual unsigned int get_damage();

	virtual bool set_defence(unsigned int defence);
	virtual unsigned int get_defence();

	virtual void set_npc_hint(const std::string &hint);
	virtual const std::string get_npc_hint();
	virtual bool react();

	virtual std::string serialize_character();
protected:
	std::string m_hint;

};

#endif //_NPC_BASE_H_