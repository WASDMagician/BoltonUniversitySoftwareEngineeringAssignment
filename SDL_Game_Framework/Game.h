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

	void OnKeyPressed();

	void Handle_Start_Keys();
	void Handle_Play_Keys();
	void Handle_Pause_Keys();
	void Handle_End_Keys();


	void Draw();
	void Draw_Start();
	void Draw_Play();
	void Draw_Pause();
	void Draw_End();

private:

	Text_Boxes *splash_box;
	Inventory *inventory;
};
#endif // _GAME_H_

