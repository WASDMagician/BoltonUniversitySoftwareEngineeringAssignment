#ifndef _OGRE_H_
#define _OGRE_H_

#include "Enemy.h"

class Ogre :
	public Enemy
{
public:
	Ogre();
	Ogre(char* imgPath, int rows, int cols);
	~Ogre();
};
#endif //_OGRE_H_
