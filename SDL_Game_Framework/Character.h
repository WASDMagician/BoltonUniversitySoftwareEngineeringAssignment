#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

#include "AW_Sprite_Interface.h"

class Character : public AW_Sprite_Interface
{
public:
	Character();
	Character(char *img, int rows, int cols, SDL_Colour colour, Transform initial_transform, std::string name,
		unsigned int health, unsigned int damage, unsigned int defence);
	~Character();

	void set_character_name(std::string name);
	std::string get_character_name();

	void set_character_health(unsigned int health);
	unsigned int get_character_health();

	void set_character_damage(unsigned int damage);
	unsigned int get_character_damage();

	void set_character_defence(unsigned int defence);
	unsigned int get_character_defence();

private:
	std::string m_name;
	unsigned int m_health;
	unsigned int m_damage;
	unsigned int m_defence;
};

#endif
