#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>
#include "Game_Object.h"

struct creation_variables
{
	char* img_path;
	int rows;
	int cols;

	std::string name;
	unsigned int health;
	unsigned int damage;
	unsigned int defence;

	unsigned int animate_speed;
};

class Character: public Game_Object
{
public:
	Character();
	Character(creation_variables *initialiser);
	
	virtual ~Character();

	virtual bool set_name(std::string name) = NULL;
	virtual std::string get_name() = NULL;

	virtual bool set_lives(unsigned int lives) = NULL;
	virtual unsigned int get_lives() = NULL;

	virtual bool set_health(unsigned int health) = NULL;
	virtual unsigned int get_health() = NULL;

	virtual bool set_damage(unsigned int damage) = NULL;
	virtual unsigned int get_damage() = NULL;

	virtual bool set_defence(unsigned int defence) = NULL;
	virtual unsigned int get_defence() = NULL;

	virtual std::string serialize_character() = NULL;

protected:
	std::string m_name;
	unsigned int m_health;
	unsigned int m_lives;
	unsigned int m_damage;
	unsigned int m_defence;
};

#endif //_CHARACTER_H_
