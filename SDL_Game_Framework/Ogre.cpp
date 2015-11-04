#include "Ogre.h"

Ogre::Ogre()
	:Enemy()
{

}

Ogre::Ogre(char* imgPath, int rows, int cols, int animationSpeed)
	: Enemy(imgPath, rows, cols, animationSpeed)
{
}

Ogre::~Ogre()
{

}