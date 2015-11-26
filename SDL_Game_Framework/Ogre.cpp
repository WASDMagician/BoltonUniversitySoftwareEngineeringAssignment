#include "Ogre.h"

Ogre::Ogre()
:Enemy()
{
}

Ogre::Ogre(char* imgPath, int rows, int cols, int animationSpeed)
: Enemy(imgPath, rows, cols, animationSpeed)
{
	set_name("Ogre");
}

Ogre::~Ogre()
{

}