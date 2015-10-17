#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>
#include "Game_Object.h"

class Character: public Game_Object
{
public:
	Character();
	Character(const std::string name, const unsigned int health, const unsigned int damage, const unsigned int defence);
	Character(char* img, int cols, int rows, std::string name, unsigned int health, unsigned int damage, unsigned int defenc);
	virtual ~Character();

	void set_character_name(const std::string &name);
	const std::string get_character_name() const;

	void set_character_health(const unsigned int health);
	const unsigned int get_character_health() const;

	void set_character_damage(const unsigned int damage);
	const unsigned int get_character_damage() const;

	void set_character_defence(const unsigned int defence);
	const unsigned int get_character_defence() const;

private:
	std::string m_name;
	unsigned int m_health;
	unsigned int m_damage;
	unsigned int m_defence;
};

#endif //_CHARACTER_H_
