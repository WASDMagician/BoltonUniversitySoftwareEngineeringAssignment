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

	int get_x();
	int get_y();
	std::string get_name();

private:
	int m_get_x;
	int m_get_y;
	std::string m_name;
};

#endif
