#ifndef _GAME_H_
#define _GAME_H_

#include "GameBase.h"
#include "Player.h"
#include "Enemy.h"
#include "Ogre.h"
#include "UI_Play_Screen.h"
#include "NPC_Shopkeeper.h"
#include "SDL_ttf.h"
#include "Text_Boxes.h"


class Game :
	public GameBase
{
public:
	Game();
	~Game();

	void Setup();
	void Logic();
	void Draw();
};
#endif // _GAME_H_

