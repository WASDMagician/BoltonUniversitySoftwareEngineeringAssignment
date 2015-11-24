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
	virtual void Attack(Character* target);
	virtual void Defend(Character* target);
	virtual bool Check_Alive();

	virtual bool set_name(std::string name);
	virtual std::string get_name();

	std::string m_name;
	virtual bool set_health(int health);
	virtual int get_health();

	virtual bool set_lives(int lives);
	virtual int get_lives();

	virtual bool set_damage(int damage);
	virtual int get_damage();

	virtual bool set_defence(int defence);
	virtual int get_defence();

	virtual void set_npc_hint(const std::string &hint);
	virtual const std::string get_npc_hint();
	virtual bool React(Character* target);

protected:
	std::string m_hint;

};

#endif //_NPC_BASE_H_