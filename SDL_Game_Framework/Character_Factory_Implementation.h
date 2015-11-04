#ifndef _CHARACTER_FACTORY_IMPLEMENTATION_H_
#define _CHARACTER_FACTORY_IMPLEMENTATION_H_

#include "Character_Factory.h"
#include <vector>

enum CHARACTER_TYPES {PLAYER, OGRE, JESUS};

class Character_Factory_Implementation :
	public Character_Factory
{
public:
	Character_Factory_Implementation();
	~Character_Factory_Implementation();

	Character* Make_Character(int characterType);

private:
	std::vector<char*> IMAGES;
};

#endif //_CHARACTER_FACTORY_IMPLEMENTATION_H_