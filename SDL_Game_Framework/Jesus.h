#ifndef _JESUS_H_
#define _JESUS_H_

#include "Enemy.h"

class Jesus :
	public Enemy
{
public:
	Jesus();
	Jesus(char* imgPath, int rows, int cols);
	~Jesus();
};
#endif // _JESUS_H_
