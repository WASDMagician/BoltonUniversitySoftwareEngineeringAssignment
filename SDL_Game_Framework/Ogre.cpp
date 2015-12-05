#include "Ogre.h"

Ogre::Ogre()
:Enemy()
{
}

Ogre::Ogre(char* imgPath, int rows, int cols)
: Enemy(imgPath, rows, cols)
{
}

Ogre::~Ogre()
{

}