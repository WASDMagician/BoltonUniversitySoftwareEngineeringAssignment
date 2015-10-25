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
#include "Inventory.h"


class Game :
	public GameBase
{
public:
	Game();
	~Game();

	void Setup();

	void Logic();
	void Logic_Start();
	void Logic_Play();
	void Logic_Pause();
	void Logic_End();

	void Draw();
	void Draw_Start();
	void Draw_Play();
	void Draw_Pause();
	void Draw_End();

private:

	Player *new_player;
	Enemy *new_enemy;
	Character *new_ogre;
	UI_Play_Screen *m_play_screen_ui;
	NPC_Shopkeeper *new_npc_shopkeeper;
	Text_Boxes *text_box;
	Inventory *inventory;
};
#endif // _GAME_H_

