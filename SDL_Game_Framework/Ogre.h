#ifndef _OGRE_H_
#define _OGRE_H_

#include "Enemy.h"

class Ogre :
	public Enemy
{
public:
	//char* img_path, unsigned int rows, unsigned int cols, string name, unsigned int health, unsigned int damage, unsigned int defence, unsigned animation_speed
	Ogre(creation_variables *initialisers);
	~Ogre();

private:
	Enemy *enemy;
};

#endif
