#ifndef _OGRE_H_
#define _OGRE_H_

#include "Enemy.h"

class Ogre :
	public Enemy
{
public:
	Ogre(creation_variables *initialisers);
	~Ogre();

private:
	Enemy *enemy;
};

#endif
