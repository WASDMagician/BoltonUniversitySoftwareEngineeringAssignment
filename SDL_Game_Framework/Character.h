#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include "AWSprite.h"

class Character : public AWSprite
{
public:
	Character();
	Character(char *img, int x, int y);
	~Character();

	int get_x();
	int get_y();

private:
	int m_get_x;
	int m_get_y;
};

#endif
