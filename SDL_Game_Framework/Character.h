#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

#include "AWSprite.h"

class Character : public AWSprite
{
public:
	Character();
	Character(char *img, int x, int y, std::string name);
	~Character();

	std::string get_character_name();

private:
	std::string m_name;
};

#endif
