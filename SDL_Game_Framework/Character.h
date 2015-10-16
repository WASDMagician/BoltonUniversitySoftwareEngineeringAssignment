#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

#include "AWSprite.h"

class Character : public AWSprite
{
public:
	Character();
	Character(char *img, const unsigned int rows, const unsigned int cols, const std::string name,
		const unsigned int health, const unsigned int damage, const unsigned int defence);
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

#endif
