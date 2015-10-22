#ifndef _GAME_H_
#define _GAME_H_

#include "GameBase.h"
#include "Player.h"
#include "Enemy.h"
#include "Ogre.h"
#include "UI_Play_Screen.h"


class Game :
	public GameBase
{
public:
	Game();
	~Game();

	void Setup();
	void Logic();
	void Draw();

	Player *new_player;
	Enemy *new_enemy;
	Character *new_ogre;
	UI_Play_Screen *m_play_screen_ui;
	
};
#endif // _GAME_H_

