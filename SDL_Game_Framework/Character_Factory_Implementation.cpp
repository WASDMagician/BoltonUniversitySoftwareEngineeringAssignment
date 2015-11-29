#include "Character_Factory_Implementation.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Ogre.h"
#include "Jesus.h"
#include "Clown.h"
#include "NPC_Hinter.h"
#include "Centipede.h"
#include "NPC_Healer.h"

Character_Factory_Implementation::Character_Factory_Implementation()
{
	IMAGES = std::vector<char*>({ "images/Fish.bmp", "images/alien.bmp", "images/jesus.bmp", "images/clown.png", "images/Centipede.png","images/Healer.png"});
}


Character_Factory_Implementation::~Character_Factory_Implementation()
{
}


Character* Character_Factory_Implementation::Make_Character(int CharacterType)
{
	switch (CharacterType)
	{
	case PLAYER:
		return new Player(IMAGES[CharacterType], 8, 1, 1);
		break;
	case OGRE:
		return new Ogre(IMAGES[CharacterType], 3, 2, 1);
		break;
	case JESUS:
		return new Jesus(IMAGES[CharacterType], 1, 1, 1);
		break;
	case CLOWN:
		return new NPC_Hinter(IMAGES[CharacterType], 1, 1, 1, "");
		break;
	case CENTIPEDE:
		return new Centipede(IMAGES[CharacterType], 1, 1, 1);
		break;
	case HEALER: 
		return new NPC_Healer(IMAGES[CharacterType], 1, 1, 1, "");
		break;
	default:
		return NULL;
	}
}